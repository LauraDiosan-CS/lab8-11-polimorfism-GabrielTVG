#pragma once
#include "RepositoryFile.h"
#include "Repository.h"
#include "Serializer.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

template <class T>
class RepositoryFileCSV :public RepositoryFile<T>
{
private:
	const char* fileName;
	Serializer<T>* serializer;
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char*, Serializer<T>*);
	void loadFromFile(const char*);
	void saveToFile();
	void addElem(T);
	void delElem(int);
	void updateElem(T, T);
	~RepositoryFileCSV();
};

template <class T>
RepositoryFileCSV<T>::RepositoryFileCSV():RepositoryFile<T>()
{
	fileName = "";
}

template <class T>
RepositoryFileCSV<T>::RepositoryFileCSV(const char* fName,Serializer<T>* serial):RepositoryFile<T>()
{
	this->fileName = fName;
	serializer = serial;
	loadFromFile(fileName);
}


template <class T>
void RepositoryFileCSV<T>::loadFromFile(const char* fileNam)
{
	string line;
	this->fileName = fileNam;
	ifstream f(this->fileName);
	while (getline(f, line))
		Repository<T>::addElem(serializer->fromString(line, ','));
	cout << "REPOCSV LOADFILE" << endl;
}

template <class T>
void RepositoryFileCSV<T>::saveToFile()
{
	ofstream fout(this->fileName);
	map<int, T> elem = this->getAll();
	for (auto itr = elem.begin(); itr != elem.end(); itr++)
		fout << itr->second->toStringDelimiter(',') << endl;
	cout << "REPOCSV SAVETOFILE" << endl;
	/*for (T t : this->getAll())
		f << t.toStringDelimiter(',') << endl;*/
}

template<class T> void RepositoryFileCSV<T>::addElem(T obj)
{
	Repository<T>::addElem(obj);
	cout << "REPOCSV ADAUGARE" << endl;
	saveToFile();
}

template<class T> void RepositoryFileCSV<T>::delElem(int nr)
{
	Repository<T>::delElem(nr);
	saveToFile();
}

template<class T> void RepositoryFileCSV<T>::updateElem(T old, T newobj)
{
	Repository<T>::updateElem(old, newobj);
	saveToFile();
}

template <class T>
RepositoryFileCSV<T>::~RepositoryFileCSV()
{

}