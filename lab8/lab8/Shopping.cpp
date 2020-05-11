#include "Shopping.h"

Shopping::Shopping()
{

}

Shopping::Shopping(const string nume, string adresa, string lista, int pret, string numeMag) :Comanda(nume, adresa, lista, pret)
{
	this->numeMagazin = numeMag;
}

Shopping::Shopping(string linie, char delim)
{
	vector<string> token = splitLine(linie, delim);
	this->nume = token[0];
	this->adresa = token[1];
	this->lista = token[2];
	this->pret = stoi(token[3]);
	this->numeMagazin = token[4];
}
Shopping::Shopping(const Shopping& s) : Comanda(s)
{
	this->numeMagazin = s.numeMagazin;
}

Shopping::~Shopping()
{

}

string Shopping::getNumeMagazin()
{
	return this->numeMagazin;
}

void Shopping::setNumeMagazin(string nume)
{
	this->numeMagazin = nume;
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
	os << "Nume: " << s.getName() << " Adresa: " << s.getAdresa() << " Lista cumparaturi: " << s.getLista() << " Pret: " << s.getPret() <<" Nume magazin: "<<s.getNumeMagazin()<< endl;
	return os;
}


string Shopping::toStringDelimiter(char delim)
{
	return nume + delim + adresa + delim + lista + delim + to_string(pret) + " " + numeMagazin;
}

string Shopping::toString()
{
	string string1, string2, string3, string4, string5;
	string1 = this->nume;
	string2 = this->adresa;
	string3 = this->lista;
	string4 = this->pret;
	string5 = this->numeMagazin;
	return string1 + " " + string2 + " " + string3 + " " + to_string(this->pret)+" "+string5;
}