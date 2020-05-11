#include "Mancare.h"

Mancare::Mancare()
{

}

Mancare::Mancare(const string nume, string adresa, string lista, int pret) :Comanda(nume, adresa, lista, pret)
{

}

Mancare::Mancare(string linie, char delim)
{
	vector<string> token = splitLine(linie, delim);
	this->nume = token[0];
	this->adresa = token[1];
	this->lista = token[2];
	this->pret = stoi(token[3]);
}
Mancare::Mancare(const Mancare& m) : Comanda(m)
{

}

Mancare::~Mancare()
{

}

ostream& operator<<(ostream & os, Mancare& m)
{
os << "Nume: " << m.getName() << " Adresa: " << m.getAdresa() << " Lista preparate: " << m.getLista() << " Pret: " << m.getPret() << endl;
return os;
}

string Mancare::toStringDelimiter(char delim)
{
	return this->nume + delim + this->adresa + delim + this->lista + delim + to_string(this->pret);
}

bool Mancare::operator==(const Mancare& manc)
{
	return Comanda::operator==(manc);
}

Mancare& Mancare::operator=(const Mancare& manc)
{
	if (this != &manc)
	{
		this->nume = manc.nume;
		this->adresa = manc.adresa;
		this->lista = manc.lista;
		this->pret = manc.pret;
	}
	return *this;
}

string Mancare::toString()
{
	string string1, string2, string3, string4;
	string1 = this->nume;
	string2 = this->adresa;
	string3 = this->lista;
	return string1 + " " + string2 + " " + string3 + " " + to_string(this->pret);
}