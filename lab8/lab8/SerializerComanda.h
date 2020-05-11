#pragma once
#include <sstream>
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Serializer.h"
class SerializerComanda :public Serializer<Comanda*> {
public:
	SerializerComanda() {}
	~SerializerComanda() {}
	inline Comanda* fromString(string, char);
};

Comanda* SerializerComanda::fromString(string line, char delimiter) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delimiter))
		tokens.push_back(item);
	if (tokens.size() == 4)
	{
		Comanda* d = new Mancare(line, delimiter);
		return d;
	}
	else
		if (tokens.size() == 5)
		{
			Comanda* d = new Shopping(line, delimiter);
			return d;
		}
}