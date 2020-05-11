#include "Service.h"


int Service::login(string nume, string parola)
{
	if (nume == "logare" && parola == "1234")
		return 1;
	else
		return 0;
}

map<int, Comanda*> Service::getAll()
{
	return repoComanda.getAll();
}

void Service::addComanda(Comanda* com)
{
	validator.validareComanda(com);
	repoComanda.addElem(com);
}

void Service::delComanda(int poz)
{
	repoComanda.delElem(poz);
}

void Service::updateComanda(Comanda*& vechi, Comanda* nou)
{
	validator.validareComanda(nou);
	repoComanda.updateElem(vechi, nou);
}

Comanda* Service::getItemFromPos(int pos)
{
	return repoComanda.getItemFromPos(pos);
}

map<int, Comanda*> Service::comandaDupaNumeClient(string nume)
{
	map<int, Comanda*> t = repoComanda.getAll();
	map<int, Comanda*> rez;
	map<int, Comanda*>::iterator itr=t.begin();
	for (auto itr = t.begin(); itr != t.end(); itr++)
		if (itr->second->getName() == nume)
			rez.insert(pair<int, Comanda*>(itr->first, itr->second));
	return rez;
}


Service::~Service()
{

}