#include "ValidareComanda.h"

using namespace std;

ComandaExceptie::ComandaExceptie(vector<string>_errors) :errors{ _errors } {}
vector<string> ComandaExceptie::getErrors() const {
	return this->errors;
}

void ComandaValidare::validareComanda(Comanda* &com)
{
	vector<string> errors;
	if (com->getLista() == "")
		errors.push_back("Lista nu poate sa fie goala!");
	if (com->getPret() <= 0)
		errors.push_back("Pretul nu poate sa fie <=0!");
	if (errors.size() > 0)
		throw ComandaExceptie(errors);
}