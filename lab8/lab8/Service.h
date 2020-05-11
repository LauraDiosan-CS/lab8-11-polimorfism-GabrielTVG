#pragma once
#include "Repository.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileCustom.h"
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"
#include "ValidareComanda.h"


class Service
{
private:
	RepositoryFile<Comanda*> repoComanda;
	ComandaValidare validator;
public:
	Service(RepositoryFile<Comanda*>r) :repoComanda(r) { repoComanda = r; };
	int login(string, string);
	map<int, Comanda*> getAll();
	void addComanda(Comanda*);
	void delComanda(int);
	void updateComanda(Comanda*&, Comanda*);
	map<int, Comanda*> comandaDupaNumeClient(string);
	Comanda* getItemFromPos(int);
	~Service();
};