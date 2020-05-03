#pragma once
#include "Comanda.h"
#include "Utils.h"
class Mancare : public Comanda
{
public:
	Mancare();
	Mancare(string, char delim);
	Mancare(const string,string,string,int);
	Mancare(const Mancare&);
	~Mancare();
	string toStringDelimiter(char);
	friend ostream& operator<<(ostream&, Mancare&);
};