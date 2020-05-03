#include "UI.h"
#include "Service.h"
#include "Repository.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileCustom.h"
#include <iostream>
using namespace std;

int main()
{
	int optiune;
	cout << "teste" << endl;
	cout << "teste reusite" << endl;
	cout << "Fisier cu care lucram: (1. csv 2. custom)" << endl;
	cin >> optiune;
	if (optiune == 1)
	{
		Repository<Mancare>* repoMancare = new RepositoryFileCSV<Mancare>("Comenzi.csv");
		((RepositoryFileCSV<Mancare>*)repoMancare)->loadFromFile();
		Repository<Shopping>* repoShopping = new RepositoryFileCSV<Shopping>("Comenzi.csv");
		((RepositoryFileCSV<Shopping>*)repoShopping)->loadFromFile();
		Service s(repoMancare, repoShopping);
		UI ui(s);
		ui.showMenu();
	}
	if (optiune == 2)
	{
		Repository<Mancare>* repoMancare = new RepositoryFileCustom<Mancare>("Comenzi.txt");
		((RepositoryFileCustom<Mancare>*)repoMancare)->loadFromFile();
		Repository<Shopping>* repoShopping = new RepositoryFileCustom<Shopping>("Comenzi.txt");
		((RepositoryFileCustom<Shopping>*)repoShopping)->loadFromFile();
		Service s(repoMancare, repoShopping);
		UI ui(s);
		ui.showMenu();
	}
	return 0;
}