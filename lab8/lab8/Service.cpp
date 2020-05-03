#include "Service.h"

Service::Service()
{

}

Service::Service(Repository<Mancare>* manc, Repository<Shopping>* shop)
{
	this->repoMancare = manc;
	this->repoShopping = shop;
}

int Service::login(string nume, string parola)
{
	if (nume == "logare" && parola == "1234")
		return 1;
	else
		return 0;
}

map<int, Mancare> Service::getAllMancare()
{
	return repoMancare->getAll();
}

map<int, Shopping> Service::getAllShopping()
{
	return repoShopping->getAll();
}

void Service::addMancare(Mancare& manc)
{
	repoMancare->addElem(manc);
	((RepositoryFile<Mancare>*)repoMancare)->saveToFile();
}

void Service::addShopping(Shopping& shop)
{
	repoShopping->addElem(shop);
	((RepositoryFile<Shopping>*)repoShopping)->saveToFile();
}

map<int, Mancare> Service::mancareDupaNumeClient(string nume)
{
	int cont = 0;
	map<int, Mancare> rez;
	map<int, Mancare> manc = repoMancare->getAll();
	map<int, Mancare>::iterator itr=manc.begin();
	while (itr != manc.end())
	{
		if (itr->second.getName() == nume)
		{
			Mancare a = itr->second;
			rez.insert(pair<int, Mancare>(cont++, a));
		}
		itr++;
	}
	return rez;
}

map<int, Shopping> Service::shoppingDupaNumeClient(string nume)
{
	int cont = 0;
	map<int, Shopping> rez;
	map<int, Shopping> shop = repoShopping->getAll();
	map<int, Shopping>::iterator itr = shop.begin();
	while (itr != shop.end())
	{
		if (itr->second.getName() == nume)
		{
			Shopping a = itr -> second;
			rez.insert(pair<int, Shopping>(cont++, a));
		}
		itr++;
	}
	return rez;
}

Service::~Service()
{

}