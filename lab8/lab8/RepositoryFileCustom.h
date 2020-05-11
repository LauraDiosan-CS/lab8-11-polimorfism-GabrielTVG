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
class RepositoryFileCustom :public RepositoryFile<T>
{
private:
	const char* fileName;
	Serializer<T>* serializer;
public:
	RepositoryFileCustom();
	RepositoryFileCustom(const char*, Serializer<T>*);
	void loadFromFile(const char*);
	void saveToFile();
	void addElem(T);
	void delElem(int);
	void updateElem(T, T);
	~RepositoryFileCustom();
};

template <class T>
RepositoryFileCustom<T>::RepositoryFileCustom() :RepositoryFile<T>()
{
	fileName = "";
}

template <class T>
RepositoryFileCustom<T>::RepositoryFileCustom(const char* fName, Serializer<T>* serial):RepositoryFile<T>()
{
	this->fileName = fName;
	serializer = serial;
	loadFromFile(fileName);
}


template <class T>
void RepositoryFileCustom<T>::loadFromFile(const char* fileNam)
{
	string line;
	this->fileName = fileNam;
	ifstream f(this->fileName);
	while (getline(f, line))
		Repository<T>::addElem(serializer->fromString(line, '/'));
	cout << "INCARCAT DIN CUSTOM" << endl;
}

template <class T>
void RepositoryFileCustom<T>::saveToFile()
{
	ofstream fout(this->fileName);
	map<int, T> elem = this->getAll();
	for (auto itr = elem.begin(); itr != elem.end(); itr++)
		fout << itr->second->toStringDelimiter('/') << endl;
	cout << "REPOCUSTOM SAVETOFILE" << endl;
	/*for (T t : this->getAll())
		f << t.toStringDelimiter('/') << endl;*/
}

template<class T> void RepositoryFileCustom<T>::addElem(T obj)
{
	Repository<T>::addElem(obj);
	cout << "REPOCUSTOM ADAUGARE" << endl;
	saveToFile();
}

template<class T> void RepositoryFileCustom<T>::delElem(int nr)
{
	Repository<T>::delElem(nr);
	saveToFile();
}

template<class T> void RepositoryFileCustom<T>::updateElem(T old, T newobj)
{
	Repository<T>::updateElem(old, newobj);
	saveToFile();
}

template <class T>
RepositoryFileCustom<T>::~RepositoryFileCustom()
{

}