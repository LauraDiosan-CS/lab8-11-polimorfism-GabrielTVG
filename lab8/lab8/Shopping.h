#pragma once
#include "Comanda.h"
#include <string>
#include "Utils.h"
class Shopping : public Comanda 
{
private:
	string numeMagazin;
public:
	Shopping();
	Shopping(const string, string, string, int, string);
	Shopping(string, char);
	Shopping(const Shopping&);
	~Shopping();
	string getNumeMagazin();
	void setNumeMagazin(string);
	Shopping& operator=(const Shopping&);
	bool operator==(const Shopping&);
	friend ostream& operator<<(ostream&, Shopping&);
	string toStringDelimiter(char);
};