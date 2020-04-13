#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Comanda {
protected:
	char* nume;
	char* adresa;
	char* lista;
	int pret;
public:
	Comanda();
	Comanda(const char*, char*, char*, int);
	Comanda(const Comanda&);
	~Comanda();
	char* getName();
	void setName(char*);
	char* getAdresa();
	void setAdresa(char*);
	char* getLista();
	void setLista(char*);
	int getPret();
	void setPret(int);
	Comanda& operator=(const Comanda&);
	bool operator==(const Comanda&);

};