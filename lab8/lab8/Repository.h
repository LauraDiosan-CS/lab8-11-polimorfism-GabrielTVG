#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"
using namespace std;
template <class T>
class Repository {
protected: 
	map<int, T>elem;
	int contor;
public:
	Repository();
	Repository(const Repository&);
	void addElem(T& );
	int findElem(T& );
	void delElem(int);
	void updateElem(int,T&);
	int dim();
	map<int,T> getAll();
	~Repository();
};

template <class T> inline Repository<T>::Repository()
{
	this->contor = 0;
}

template <class T> inline Repository<T>::Repository(const Repository& r)
{
	this->elem = r.elem;
	this->contor = r.contor;
}

template <class T> inline void Repository<T>::addElem(T& a)
{
	this->elem.insert(pair<int, T>(this->contor++, a));
}

//template <class T> inline int Repository<T>::findElem(T& a)
//{
//	map<int, T>::iterator it = elem.begin();
//	while (it != elem.end()) {
//		if (it->second == a)
//			return it->first;
//		else
//			it++;
//	}
//	return -1;
//}

template <class T> inline void Repository<T>::delElem(int nr)
{
	elem.erase(nr);
}

//template <class T> inline void Repository<T>::updateElem(int pozitie,T& noua)
//{
//	map<int, T>::iterator itf = elem.find(pozitie);
//	if (itf != elem.end())
//		this->elem[pozitie] = noua;
//}

template <class T> inline int Repository<T>::dim()
{
	return this->contor;
}

template <class T> inline map<int, T>Repository<T>::getAll()
{
	return this->elem;
}

template <class T> inline Repository<T>::~Repository()
{
	elem.clear();
	contor = 0;
}