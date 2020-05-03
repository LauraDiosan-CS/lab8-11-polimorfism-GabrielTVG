#pragma once
#include "Service.h"

class UI
{
private:
	Service ser;
	int login();
	void adaugareMancare();
	void adaugareShopping();
	void afisareComenzi();
	void cautareDupaNume();
public:
	UI();
	UI(Service&);
	void showMenu();
	~UI();
};