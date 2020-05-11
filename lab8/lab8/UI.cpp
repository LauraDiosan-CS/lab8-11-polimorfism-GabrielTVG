#include "UI.h"


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

void UI::adaugareComanda()
{
	string nume, adresa, lista, magazin;
	int pret, optiune;
	cout <<endl<<"Mancare(1) sau Shopping(2)? : " << endl;
	cin >> optiune;
	if (optiune == 1)
	{
		try {
			cout << "Nume client:\n";
			cin.ignore();
			getline(cin, nume);
			cout << "Adresa livrare: " << endl;
			//cin.ignore();
			getline(cin, adresa);
			cout << "Lista preparate" << endl;
			//cin.ignore();
			getline(cin, lista);
			cout << "Pret total: " << endl;
			cin >> pret;
			Mancare com(nume, adresa, lista, pret);
			Comanda* comanda = new Mancare(com);
			ser.addComanda(comanda);
			cout << "Mancare adaugata!" << endl;

		}
		catch (ComandaExceptie err)
		{
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i] << endl;
		}
	}
	if (optiune == 2)
	{
		try {
			cout << "Nume client:\n";
			cin.ignore();
			getline(cin, nume);
			cout << "Adresa livrare: " << endl;
			//cin.ignore();
			getline(cin, adresa);
			cout << "Lista cumparaturi: " << endl;
			//cin.ignore();
			getline(cin, lista);
			cout << "Pret total: " << endl;
			cin >> pret;
			cout << "Nume magazin: " << endl;
			cin.ignore();
			getline(cin, magazin);
			Shopping s(nume, adresa, lista, pret, magazin);
			Comanda* comanda = new Shopping(s);
			ser.addComanda(comanda);
			cout << "Shopping adaugat!" << endl;
		}
		catch (ComandaExceptie err)
		{
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i] << endl;
		}
	}

}


void UI::afisareComenzi()
{
	map<int, Comanda*> t = ser.getAll();
	for (auto itr = t.begin(); itr != t.end(); itr++)
		cout << "Cheia: " << itr->first << ' ' << itr->second->toString() << endl;
}

void UI::stergereComanda()
{
	int poz;
	cout << "Cheia in mapa la comanda care vrem sa o stergem: " << endl;
	cin >> poz;
	ser.delComanda(poz);
}

void UI::updateComanda()
{
	string numeNou,adresaNoua,listaNoua,magazinNou;
	int pretNou, optiune,poz;
	cout << "Ce comanda este cea care o actualizam? (1 Mancare, 2 Shopping): " << endl;
	cin >> optiune;
	if (optiune == 1)
	{
		try {
			cout << "Pozitie in mapa: " << endl;
			cin >> poz;
			cout << "Nume client nou: " << endl;
			cin.ignore();
			getline(cin, numeNou);
			cout << "Adresa livrare noua: " << endl;
			getline(cin, adresaNoua);
			cout << "Lista preparate noua: " << endl;
			getline(cin, listaNoua);
			cout << "Pret total nou: " << endl;
			cin >> pretNou;
			Comanda* comanda = ser.getItemFromPos(poz);
			Mancare com2(numeNou, adresaNoua, listaNoua, pretNou);
			Comanda* comanda2 = new Mancare(com2);
			ser.updateComanda(comanda, comanda2);
		}
		catch (ComandaExceptie err)
		{
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i] << endl;
		}
	}
	if (optiune == 2)
	{
		try {
			cout << "Pozitie in mapa: " << endl;
			cin >> poz;
			cout << "Nume client nou: " << endl;
			cin.ignore();
			getline(cin, numeNou);
			cout << "Adresa livrare noua: " << endl;
			getline(cin, adresaNoua);
			cout << "Lista cumparaturi noua: " << endl;
			getline(cin, listaNoua);
			cout << "Pret total nou: " << endl;
			cin >> pretNou;
			cout << "Nume magazin nou: " << endl;
			cin.ignore();
			getline(cin, magazinNou);
			Shopping s2(numeNou, adresaNoua, listaNoua, pretNou, magazinNou);
			Comanda* comanda = ser.getItemFromPos(poz);
			Comanda* comanda2 = new Shopping(s2);
			ser.updateComanda(comanda, comanda2);
			cout << "Shopping adaugat!" << endl;
		}
		catch (ComandaExceptie err)
		{
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i] << endl;
		}
	}

}
void UI::cautareDupaNume()
{
	string nume;
	cout << "Numele clientului: " << endl;
	cin >> nume;
	map<int, Comanda*> manc = ser.comandaDupaNumeClient(nume);
	map<int, Comanda*>::iterator itr1 = manc.begin();
	while (itr1 != manc.end())
	{
		cout << "Cheia: " << itr1->first << ' ' << itr1->second->toString() << endl;
		itr1++;
	}
}

void UI::showMenu()
{
	int logat = 0, ok = 1, optiune;
	while (ok)
	{
		while (logat == 0)
			logat = login();
		cout << "1.Adaugare comanda 2. Afisare comenzi 3. Cautare dupa nume 4.Update comanda 5.Stergere comanda 6.Logout 7.Exit"<<endl;
		cin >> optiune;
		if (optiune == 1)
		{
			adaugareComanda();
			continue;
		}

		if (optiune == 2)
		{
			afisareComenzi();
			continue;
		}
		if (optiune == 3)
		{
			cautareDupaNume();
			continue;
		}
		if (optiune == 4)
		{
			updateComanda();
			continue;
		}
		if (optiune == 5)
		{
			stergereComanda();
			continue;
		}
		if (optiune == 6)
		{
			logat = 0;
			continue;
		}
		if (optiune == 7)
		{
			ok = 0;
			cout << "Cya later" << endl;
		}
	}
}