#pragma once
#include "Comanda.h"
#include <string>
#include <vector>

using namespace std;

class ComandaExceptie
{
protected:
	vector<string> errors;
public:
	ComandaExceptie(vector<string> _errors);
	vector<string> getErrors() const;
};

class ComandaValidare
{
public:
	ComandaValidare()
	{

	}
	virtual void validareComanda(Comanda*&);
	~ComandaValidare()
	{

	}
};