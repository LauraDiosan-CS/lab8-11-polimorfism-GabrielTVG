#pragma once
#include "Repository.h"
#include "Utils.h"
#include <fstream>
template <class T> class RepositoryFile : public Repository<T>
{
protected:
	const char* fileName;
public:
	RepositoryFile();
	RepositoryFile(const char* Name);
	virtual void loadFromFile();
	virtual void saveToFile();
	~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile() :Repository<T>()
{
	
}

template <class T>
RepositoryFile<T>::RepositoryFile(const char* Name)
{
	fileName = Name;
}

template <class T>
void RepositoryFile<T>::loadFromFile()
{

}

template<class T>
void RepositoryFile<T>::saveToFile()
{

}


template<class T>
RepositoryFile<T>::~RepositoryFile()
{

}