#pragma once
#include "Repository.h"
#include "Tabla.h"
#include "Element.h"
//#include "RepositoryFile.h"
//#include "RepositoryFileCSV.h"
//#include "RepositoryFileCustom.h"


class Service
{
private:
	Repository<Tabla*> *repoTabla;
public:
	Service(Repository<Tabla*>*t) :repoTabla(t) { repoTabla = t; };
	map<int, Tabla*> getAll();
	void addAvion(Comanda*);
	void delComanda(int);
	void updateComanda(Comanda*&, Comanda*);
	map<int, Comanda*> comandaDupaNumeClient(string);
	Comanda* getItemFromPos(int);
	~Service();
};