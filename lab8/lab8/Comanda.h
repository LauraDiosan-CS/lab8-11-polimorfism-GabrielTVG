#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Utils.h"
using namespace std;
class Comanda {
protected:
	string nume;
	string adresa;
	string lista;
	int pret;
public:
	Comanda();
	Comanda(const string, string, string, int);
	Comanda(string, char);
	Comanda(const Comanda&);
	virtual ~Comanda();
	string getName();
	void setName(string);
	string getAdresa();
	void setAdresa(string);
	string getLista();
	void setLista(string);
	int getPret();
	void setPret(int);
	virtual Comanda& operator=(const Comanda&);
	virtual bool operator==(const Comanda&);
	virtual string toStringDelimiter(char);
	friend ostream& operator<<(ostream& os, Comanda);
	virtual string toString();
};