#include "Service.h"
#include "Test.h"
#include <cassert>
#include <iostream>

using namespace std;

void testCSV()
{
	const char* fileName = "Comenzi.csv";
	Mancare a("test", "petru rares", "3 masline", 6);
	RepositoryFile<Mancare>* repoMancare = new RepositoryFileCSV<Mancare>(fileName);
	((RepositoryFileCSV<Mancare>*)repoMancare)->loadFromFile();
	assert(repoMancare->dim() == 0);

	repoMancare->addElem(a);
	assert(repoMancare->dim() == 1);
	repoMancare->delElem(0);
	assert(repoMancare->dim() == 0);
}

void testCustom()
{
	const char* fileName = "Comenzi.txt";
	Mancare a("test", "petru rares", "3 masline", 6);
	RepositoryFile<Mancare>* repoMancare = new RepositoryFileCustom<Mancare>(fileName);
	((RepositoryFileCustom<Mancare>*)repoMancare)->loadFromFile();
	assert(repoMancare->dim() == 0);

	repoMancare->addElem(a);
	assert(repoMancare->dim() == 1);
	repoMancare->delElem(0);
	assert(repoMancare->dim() == 0);
}