#pragma once
#include "RepositoryFile.h"
#include "Utils.h"
#include "string"
#include <algorithm>
template <class T>
class RepositoryFileCustom :public RepositoryFile<T>
{
public:
	RepositoryFileCustom();
	RepositoryFileCustom(const char*);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileCustom();
};

template <class T>
inline RepositoryFileCustom<T>::RepositoryFileCustom()
{

}

template <class T>
inline RepositoryFileCustom<T>::RepositoryFileCustom(const char* fName) :RepositoryFile<T>(fName)
{

}


template <class T>
inline void RepositoryFileCustom<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line))
	{
	/*	int n = count(line.begin(), line.end(), '/');
		if (n == 4)
		{
			Shopping ob(line, '/');
			Repository<T>::addElem(ob);
		}
		else
			if (n == 3)
			{
				Mancare ob(line, '/');
				Repository<T>::addElem(ob);
			}*/
		T ob(line, '/');
		Repository<T>::addElem(ob);
		//this->elem.insert(pair<int, T>(this->contor++, a));
	}
}

template <class T>
inline void RepositoryFileCustom<T>::saveToFile()
{
	ofstream f(RepositoryFile<T>::fileName);
	map<int, T> t = Repository<T>::elem;
	for (auto itr = t.begin();itr!=t.end();itr++)
	{
		f << itr->second.toStringDelimiter('/') << endl;
	}
}

template <class T>
inline RepositoryFileCustom<T>::~RepositoryFileCustom()
{

}