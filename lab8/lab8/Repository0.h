#pragma once
#include "Comanda.h"

#include <map>
using namespace std;
template <class T>
class Repository0
{
protected:
	
public:
	virtual void addElem(T);
	virtual int findElem(T);
	virtual void delElem(int);
	virtual void updateElem(int, T);
	virtual int dim();
	virtual map<int, T> getAll();
};