#include "Comanda.h"
using namespace std;

Comanda::Comanda()
{
	pret = 0;
}

Comanda::Comanda(const string num, string adres, string list, int pre)
{
	this->nume = num;
	this->adresa = adres;
	this->lista = list;
	this->pret = pre;
}

Comanda::Comanda(string linie, char delim)
{
	vector<string> token = splitLine(linie, delim);
	this->nume = token[0];
	this->adresa = token[1];
	this->lista = token[2];
	this->pret = stoi(token[3]);
}
Comanda::Comanda(const Comanda& c)
{
	this->nume = c.nume;
	this->adresa = c.adresa;
	this->lista = c.lista;
	this->pret = c.pret;
}

Comanda::~Comanda()
{
	
}

string Comanda::getName()
{
	return this->nume;
}

void Comanda::setName(string name)
{
	this->nume = name;
}

string Comanda::getAdresa()
{
	return this->adresa;
}

void Comanda::setAdresa(string adress)
{
	this->adresa = adress;
}

string Comanda::getLista()
{
	return this->lista;
}

void Comanda::setLista(string list)
{
	this->lista = list;
}

int Comanda::getPret()
{
	return this->pret;
}

void Comanda::setPret(int pre)
{
	this->pret = pre;
}

Comanda& Comanda::operator=(const Comanda& c)
{
	if (this != &c)
	{
		this->nume = c.nume;
		this->adresa = c.adresa;
		this->lista = c.lista;
		this->pret = c.pret;
	}
	return *this;
}

bool Comanda::operator==(const Comanda& c)
{
	return (nume == c.nume && adresa == c.adresa && lista == c.lista && pret == c.pret);
}

ostream& operator<<(ostream& os, Comanda c)
{
	os << "Nume: " << c.getName() << " Adresa: " << c.getAdresa() << " Lista preparate: " << c.getLista() << " Pret: " << c.getPret() << endl;
	return os;
}

string Comanda::toStringDelimiter(char delim)
{
	return nume + delim + adresa + delim + lista + delim + to_string(this->pret);
}

string Comanda::toString()
{
	string string1, string2, string3, string4;
	string1 = this->nume;
	string2 = this->adresa;
	string3 = this->lista;
	return string1 + " " + string2 + " " + string3 + " " + to_string(this->pret);
}