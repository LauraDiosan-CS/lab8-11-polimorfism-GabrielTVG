#include "Shopping.h"

Shopping::Shopping()
{

}

Shopping::Shopping(const string nume, string adresa, string lista, int pret, string numeMag) :Comanda(nume, adresa, lista, pret)
{
	numeMagazin = numeMag;
}

Shopping::Shopping(string linie, char delim)
{
	vector<string> token = splitLine(linie, delim);
	nume = token[0];
	adresa = token[1];
	lista = token[2];
	pret = stoi(token[3]);
	numeMagazin = token[4];
}
Shopping::Shopping(const Shopping& s) : Comanda(s)
{
	numeMagazin = s.numeMagazin;
}

Shopping::~Shopping()
{

}

string Shopping::getNumeMagazin()
{
	return numeMagazin;
}

void Shopping::setNumeMagazin(string nume)
{
	numeMagazin = nume;
}

Shopping& Shopping::operator=(const Shopping& s)
{
	this->Comanda::operator=(s);
	this->numeMagazin = s.numeMagazin;
	return *this;
}

bool Shopping::operator==(const Shopping& s)
{
	return (Comanda::operator==(s) && (numeMagazin == s.numeMagazin));
}

ostream& operator<<(ostream& os, Shopping& s)
{
	os << "Nume: " << s.nume << " Adresa: " << s.adresa << " Lista cumparaturi: " << s.lista << " Pret: " << s.pret <<" Nume magazin: "<<s.numeMagazin<< endl;
	return os;
}


string Shopping::toStringDelimiter(char delim)
{
	return nume + delim + adresa + delim + lista + delim + to_string(pret) + " " + numeMagazin;
}