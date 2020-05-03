#pragma once
#include "Repository.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileCustom.h"
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"


class Service
{
private:
	Repository<Mancare>* repoMancare;
	Repository<Shopping>* repoShopping;

public:
	Service();
	Service(Repository<Mancare>*,Repository<Shopping>*);
	int login(string, string);
	map<int, Mancare> getAllMancare();
	map<int, Shopping> getAllShopping();
	void addMancare(Mancare&);
	void addShopping(Shopping&);
	map<int, Mancare> mancareDupaNumeClient(string);
	map<int, Shopping> shoppingDupaNumeClient(string);
	~Service();
};