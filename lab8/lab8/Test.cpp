#include "Service.h"
#include "Test.h"
#include "Serializer.h"
#include "SerializerComanda.h"
#include "RepositoryFile.h"
#include <cassert>
#include <iostream>

using namespace std;

void testCSV()
{
	const char* fileName = "Comenzi.csv";
	SerializerComanda* serial = new SerializerComanda();
	RepositoryFileCSV<Comanda*> repoCSV("Comenzi.csv", serial);
	Mancare a("test", "petru rares", "3 masline", 6);
	Comanda* comanda = new Mancare(a);
	//Mancare com(nume, adresa, lista, pret);
	//Comanda* comanda = new Mancare(com);
	//ser.addComanda(comanda);
	cout << repoCSV.dim();
	assert(repoCSV.dim() == 3);

	repoCSV.addElem(comanda);
	assert(repoCSV.dim() == 4);
	repoCSV.delElem(3);
}

void testCustom()
{
	const char* fileName = "Comenzi.txt";
	SerializerComanda* serial = new SerializerComanda();
	RepositoryFileCustom<Comanda*> repoCustom("Comenzi.txt", serial);
	Mancare a("test", "petru rares", "3 masline", 6);
	Comanda* comanda = new Mancare(a);
	assert(repoCustom.dim() == 2);

	repoCustom.addElem(comanda);
	assert(repoCustom.dim() == 3);
	repoCustom.delElem(2);
}