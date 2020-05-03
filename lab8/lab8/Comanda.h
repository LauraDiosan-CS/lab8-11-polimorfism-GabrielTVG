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
	~Comanda();
	string getName();
	void setName(string);
	string getAdresa();
	void setAdresa(string);
	string getLista();
	void setLista(string);
	int getPret();
	void setPret(int);
	Comanda& operator=(const Comanda&);
	bool operator==(const Comanda&);
	virtual string toStringDelimiter(char) = 0;
};