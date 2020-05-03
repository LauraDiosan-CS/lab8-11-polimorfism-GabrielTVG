#include "Validare.h"
#include <algorithm>
Validare::Validare()
{

}
Validare::~Validare()
{

}

int Validare::validareProduse(string produse)
{
	if (produse == "" || count(produse.begin(), produse.end(), ' ') == produse.size())
		return 0;
	return 1;
}

int Validare::validarePret(int pret)
{
	if (pret <= 0)
		return 0;
	return 1;
}