#include "UI.h"

UI::UI()
{

}

UI::UI(Service& serv)
{
	ser = serv;
}

UI::~UI()
{

}

int UI::login()
{
	int ok;
	string user, parola;
	cout << "User: " << endl;
	cin >> user;
	cout << endl << "Parola: " << endl;
	cin >> parola;
	cout << endl;
	ok = ser.login(user, parola);
	return ok;
}

void UI::adaugareMancare()
{
	string nume, adresa, lista;
	int pret, ok = 1;
	cout << "Nume client: " << endl;
	cin >> nume;
	cout << "Adresa livrare: " << endl;
	cin >> adresa;
	cout << "Lista preparate" << endl;
	cin >> lista;
	cout << "Pret total: " << endl;
	cin >> pret;
	Mancare m(nume, adresa, lista, pret);
	ser.addMancare(m);
}

void UI::adaugareShopping()
{
	string nume, adresa, lista, magazin;
	int pret, ok = 1;
	cout << "Nume client: " << endl;
	cin >> nume;
	cout << "Adresa livrare: " << endl;
	cin >> adresa;
	cout << "Lista preparate" << endl;
	cin >> lista;
	cout << "Pret total: " << endl;
	cin >> pret;
	cout << "Nume magazin: " << endl;
	cin >> magazin;
	Shopping s(nume, adresa, lista, pret, magazin);
	ser.addShopping(s);
}

void UI::afisareComenzi()
{
	map<int, Mancare> manc = ser.getAllMancare();
	map<int, Shopping> shop = ser.getAllShopping();
	map<int, Mancare>::iterator itr1 = manc.begin();
	map<int, Shopping>::iterator itr2 = shop.begin();
	cout << "Comenzi mancare:" << endl;
	while (itr1 != manc.end())
	{
		cout << "Cheia: " << itr1->first << ' ' << itr1->second;
		itr1++;
	}
	cout << "Comenzi shopping:" << endl;
	while (itr2 != shop.end())
	{
		cout << "Cheia: " << itr2->first << ' ' << itr2->second;
		itr2++;
	}
}

void UI::cautareDupaNume()
{
	string nume;
	cout << "Numele clientului: " << endl;
	cin >> nume;
	map<int, Mancare> manc = ser.mancareDupaNumeClient(nume);
	map<int, Shopping> shop = ser.shoppingDupaNumeClient(nume);
	map<int, Mancare>::iterator itr1 = manc.begin();
	map<int, Shopping>::iterator itr2 = shop.begin();
	cout << "Comenzi mancare:" << endl;
	while (itr1 != manc.end())
	{
		cout << "Cheia: " << itr1->first << ' ' << itr1->second;
		itr1++;
	}
	cout << "Comenzi shopping:" << endl;
	while (itr2 != shop.end())
	{
		cout << "Cheia: " << itr2->first << ' ' << itr2->second;
		itr2++;
	}
}

void UI::showMenu()
{
	int logat = 0, ok = 1, optiune;
	while (ok)
	{
		while (logat == 0)
			logat = login();
		cout << "1.Adaugare mancare 2. Adaugare shopping 3. Afisare comenzi 4. Cautare dupa nume 5.Logout 6.Exit"<<endl;
		cin >> optiune;
		if (optiune == 1)
		{
			adaugareMancare();
			continue;
		}
		if (optiune == 2)
		{
			adaugareShopping();
			continue;
		}
		if (optiune == 3)
		{
			afisareComenzi();
			continue;
		}
		if (optiune == 4)
		{
			cautareDupaNume();
			continue;
		}
		if (optiune == 5)
		{
			logat = 0;
			continue;
		}
		if (optiune == 6)
		{
			ok = 0;
			cout << "Cya later" << endl;
		}
	}
}