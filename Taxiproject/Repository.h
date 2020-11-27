#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <fstream>

#include<iostream>
using namespace std;
#include <vector>
template<class T>
class Repository
{
protected:


	vector <T> entity;

	bool sync;



public:
	bool Add(T);
	string GetStorageName() {
		T t;
		return t.GetStorageName();
	}
	
	void ReadFromStorage();
	void WriteToStorage();

	vector <T> GetEntity() {
		return entity;
	}

	bool deleteByIndex(int ind) {
		entity.erase(entity.begin() + ind);
		if (sync) {
			WriteToStorage();
		}
		return true;
	}
	Repository(bool sync = false);
	~Repository();
};


template<class T>
Repository<T>::Repository(bool sync)
{
	this->sync = sync;

	ReadFromStorage();
}
template<class T>
Repository<T>::Repository::~Repository()
{
	WriteToStorage();

}
template<class T>
bool Repository<T>::Add(T en) {//батьківський клас тільки через *
	entity.push_back(en);
	if (sync) {
		WriteToStorage();
	}
	return true;
}
template<class T>
void Repository<T>::ReadFromStorage() {
	ifstream fin(GetStorageName());
	

	if (!fin)
	{
		cout << ("Can't open a file ");
		exit(1);
	}

	while (!fin.eof()) {

		T tx;
		fin >> tx;
		Add(tx);


	}
	fin.close();
}
template<class T>
void Repository<T>::WriteToStorage()
{
	ofstream fout(GetStorageName(),ios::out);
	int tmp = entity.size();
	for (int i = 0; i < tmp; i++)
	{
		fout << entity[i];
		if (i < tmp - 1) {
			fout << endl;
		}

	}

	fout.close();


}
#endif