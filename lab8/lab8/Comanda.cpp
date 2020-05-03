#include "Comanda.h"
using namespace std;

Comanda::Comanda()
{
	pret = 0;
}

Comanda::Comanda(const string num, string adres, string list, int pre)
{
	nume = num;
	adresa = adres;
	lista = list;
	pret = pre;
}

Comanda::Comanda(string linie, char delim)
{
	vector<string> token = splitLine(linie, delim);
	nume = token[0];
	adresa = token[1];
	lista = token[2];
	pret = stoi(token[3]);
}
Comanda::Comanda(const Comanda& c)
{
	nume = c.nume;
	adresa = c.adresa;
	lista = c.lista;
	pret = c.pret;
}

Comanda::~Comanda()
{
	pret = 0;
}

string Comanda::getName()
{
	return nume;
}

void Comanda::setName(string name)
{
	nume = name;
}

string Comanda::getAdresa()
{
	return adresa;
}

void Comanda::setAdresa(string adress)
{
	adresa = adress;
}

string Comanda::getLista()
{
	return lista;
}

void Comanda::setLista(string list)
{
	lista = list;
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
		nume = c.nume;
		adresa = c.adresa;
		lista = c.lista;
		pret = c.pret;
	}
	return *this;
}

bool Comanda::operator==(const Comanda& c)
{
	return (nume == c.nume && adresa == c.adresa && lista == c.lista && pret == c.pret);
}
