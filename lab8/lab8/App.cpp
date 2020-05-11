#include "UI.h"
#include "Service.h"
#include "Repository.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileCustom.h"
#include "ValidareComanda.h"
#include "Test.h"
#include "SerializerComanda.h"
#include <iostream>
using namespace std;

int main()
{
	int optiune;
	cout << "teste" << endl;
	testCSV();
	testCustom();
	cout << "teste reusite" << endl;
	cout << "Fisier cu care lucram: (1. csv 2. custom)" << endl;
	cin >> optiune;
	if (optiune == 1)
	{
		SerializerComanda* serial = new SerializerComanda();
		RepositoryFileCSV<Comanda*> repoCSV("Comenzi.csv", serial);
		Service serv(repoCSV);
		UI UI(serv);
		UI.showMenu();
	}
	if (optiune == 2)
	{
		SerializerComanda* serial = new SerializerComanda();
		RepositoryFileCustom<Comanda*> repoCustom("Comenzi.txt", serial);
		Service serv(repoCustom);
		UI UI(serv);
		UI.showMenu();
	}
	return 0;
}