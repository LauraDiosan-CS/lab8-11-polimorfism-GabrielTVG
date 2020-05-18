#pragma once
class Tabla
{
protected:
	int numarLini;
	int numarColoane;
	int tabla[numarLini][numarColoane];
public:
	Tabla();
	~Tabla();
	int getNumarLini();
	int getNumarColoane();
	int getTabla();
	void setNumarLini(int);
	void setNumarColoane(int);

};