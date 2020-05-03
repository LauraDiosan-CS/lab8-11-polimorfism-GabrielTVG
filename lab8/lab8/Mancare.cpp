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
	nume = token[0];
	adresa = token[1];
	lista = token[2];
	pret = stoi(token[3]);
}
Mancare::Mancare(const Mancare& m) : Comanda(m)
{

}

Mancare::~Mancare()
{

}

ostream& operator<<(ostream & os, Mancare& m)
{
os << "Nume: " << m.nume << " Adresa: " << m.adresa << " Lista preparate: " << m.lista << " Pret: " << m.pret << endl;
return os;
}

string Mancare::toStringDelimiter(char delim)
{
	return nume + delim + adresa + delim + lista + delim + to_string(pret);
}