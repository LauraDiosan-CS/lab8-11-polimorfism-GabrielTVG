#pragma once
#include "Service.h"

class UI
{
private:
	Service ser;
public:
	UI(Service& serv) :ser(serv) { ser = serv; };
	void showMenu();
	int login();
	void adaugareComanda();
	void afisareComenzi();
	void stergereComanda();
	void updateComanda();
	void cautareDupaNume();
	~UI();
};