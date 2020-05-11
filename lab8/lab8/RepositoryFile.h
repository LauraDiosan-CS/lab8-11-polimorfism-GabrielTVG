#pragma once
#include "Repository.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <map>
#include "Serializer.h"
using namespace std;


template <class T> class RepositoryFile : public Repository<T>
{
protected:
	const char* fileName;
	char delimiter;
	Serializer<T>* serializer;
public:
	RepositoryFile();
	RepositoryFile(const char*,const char, Serializer<T>*);
	virtual void loadFromFile(const char*, const char);
	virtual void saveToFile();
	virtual void addElem(T);
	virtual void delElem(int);
	virtual void updateElem(T, T);
	map<int,T> findElem(int);
	T getItemFromPos(int);
	~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile() :Repository<T>()
{
	this->fileName = "";
	delimiter = ' ';
}

template <class T>
RepositoryFile<T>::RepositoryFile(const char* filename,const char delimit, Serializer<T>* serial):Repository<T>()
{
	this->fileName = filename;
	serializer = serial;
	loadFromFile(fileName, delimit);
}

template <class T>
void RepositoryFile<T>::loadFromFile(const char* filename,const char delimiter)
{
	this->fileName = filename;
	this->delimiter = delimiter;
	ifstream fin(fileName);
	string line;
	while (getline(fin, line))
		Repository<T>::addElem(serializer->fromString(line, delimiter));
	cout << "Incarcat din repoFile" << endl;
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
	ofstream fout(this->fileName);
	map<int, T> elem = this->getAll();
	//for (T t : this->getAll())
	//	fout << t.toStringDelimiter(this->delimiter) << endl;
	for (auto itr = elem.begin(); itr != elem.end(); itr++)
		fout << itr->second->toStringDelimiter(this->delimiter) << endl;
	cout << "REPOFILE SAVETOFILE" << endl;
}


template<class T> void RepositoryFile<T>::addElem(T obj)
{
	Repository<T>::addElem(obj);
	saveToFile();
	cout << "REPOFILE ADAUGARE" << endl;
}

template<class T> void RepositoryFile<T>::delElem(int nr)
{
	Repository<T>::delElem(nr);
}

template<class T> void RepositoryFile<T>::updateElem(T old, T newobj)
{
	Repository<T>::updateElem(old, newobj);
}

template <class T> map<int,T> RepositoryFile<T>::findElem(int poz)
{
	return Repository<T>::findElem(poz);
}

template <class T> T RepositoryFile<T>::getItemFromPos(int poz)
{
	return Repository<T>::getItemFromPos(poz);
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{

}