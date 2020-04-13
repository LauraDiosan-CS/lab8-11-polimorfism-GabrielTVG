#include "Comanda.h"
using namespace std;

Comanda::Comanda()
{
	nume = NULL;
	adresa = NULL;
	lista = NULL;
	pret = 0;
}

Comanda::Comanda(const char* num, char* adres, char* list, int pre)
{
	nume = new char[strlen(num) + 1];
	strcpy_s(nume, strlen(num) + 1, num);
	adresa = new char[strlen(adres) + 1];
	strcpy_s(adresa, strlen(adres) + 1, adres);
	lista = new char[strlen(list) + 1];
	strcpy_s(lista, strlen(list) + 1, list);
	pret = pre;
}

Comanda::Comanda(const Comanda& c)
{
	nume = new char[strlen(c.nume) + 1];
	strcpy_s(nume, strlen(c.nume) + 1, c.nume);
	adresa = new char[strlen(c.adresa) + 1];
	strcpy_s(adresa, strlen(c.adresa) + 1, c.adresa);
	lista = new char[strlen(c.lista) + 1];
	strcpy_s(lista, strlen(c.lista) + 1, c.lista);
	pret = c.pret;
}

Comanda::~Comanda()
{
	if (nume)
	{
		delete[] nume;
		nume = NULL;
	}
	if (adresa)
	{
		delete[] adresa;
		adresa = NULL;
	}
	if (lista)
	{
		delete[] lista;
		lista = NULL;
	}
	pret = 0;
}

char* Comanda::getName()
{
	return nume;
}

void Comanda::setName(char* name)
{
	if (nume)
		delete[] nume;
	nume = new char[strlen(name) + 1];
	strcpy_s(nume, strlen(name) + 1, name);
}

char* Comanda::getAdresa()
{
	return adresa;
}

void Comanda::setAdresa(char* adress)
{
	if (adresa)
		delete[]adresa;
	adresa = new char[strlen(adress) + 1];
	strcpy_s(adresa, strlen(adress) + 1, adress);
}

char* Service::getLista()
{
	return lista;
}

void Comanda::setLista(char* list)
{
	if (lista)
		delete[] lista;
	lista = new char[strlen(list) + 1];
	strcpy_s(lista, strlen(list) + 1, list);
}

int Comanda::getPret()
{
	return pret;
}

void Comanda::setPret(int pre)
{
	pret = pre;
}

Comanda& Comanda::operator=(const Comanda& c)
{
	if (this != &c)
	{
		if (nume)
			delete[] nume;
		if (adresa)
			delete[] adresa;
		if (lista)
			delete[] lista;
		nume = new char[strlen(c.nume) + 1];
		strcpy_s(nume, strlen(c.nume) + 1, c.nume);
		adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(adresa, strlen(c.adresa) + 1, c.adresa);
		lista = new char[strlen(c.lista) + 1];
		strcpy_s(lista, strlen(c.lista) + 1, c.lista);
		pret = c.pret;
	}
	return *this;
}

bool Comanda::operator==(const Comanda& c)
{
	return (strcmp(nume, c.nume) == 0 && strcmp(adresa, c.adresa) == 0 && strcmp(lista, c.lista) == 0 && pret == c.pret);
}
