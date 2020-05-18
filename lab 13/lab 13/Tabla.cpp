#include "Tabla.h"
using namespace std;

Tabla::Tabla()
{
	numarLini = 0;
	numarColoane = 0;
}

Tabla::~Tabla()
{
	
}

int Tabla::getNumarLini()
{
	return this->numarLini;
}

int Tabla::getNumarColoane()
{
	return this->numarColoane;
}

int Tabla::getTabla()
{
	return this->tabla;
}
void Tabla::setNumarLini(int linie)
{
	this->numarLini = linie;
}

void Tabla::setNumarColoane(int coloana)
{
	this->numarColoane = coloana;
}