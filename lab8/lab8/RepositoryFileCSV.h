#pragma once
#include "RepositoryFile.h"
#include "Utils.h"
#include <iostream>
#include <string>
template <class T>
class RepositoryFileCSV :public RepositoryFile<T>
{
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char*);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileCSV();
};

template <class T>
RepositoryFileCSV<T>::RepositoryFileCSV()
{

}

template <class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fName) :RepositoryFile<T>(fName)
{

}


template <class T>
void RepositoryFileCSV<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f,line))
	{
		T ob(line, ',');
		Repository<T>::addElem(ob);
		//this->elem.insert(pair<int, T>(this->contor++, a));
		
	}
}

template <class T>
void RepositoryFileCSV<T>::saveToFile()
{
	ofstream f(RepositoryFile<T>::fileName);
	map<int, T> t = Repository<T>::elem;
	for (auto itr=t.begin();itr!=t.end();itr++)
	{
		f << itr->second.toStringDelimiter(',') << endl;
	}
}

template <class T>
RepositoryFileCSV<T>::~RepositoryFileCSV()
{

}