#include "Element.h"
using namespace std;

Element::Element()
{
	pozX = 0;
	pozY = 0;
	orientare = 0;
}
Element::~Element()
{

}

int Element::getPozX()
{
	return this->pozX;
}

int Element::getPozY()
{
	return this->pozY;
}

int Element::getOrientare()
{
	return this->orientare;
}

void Element::setPozX(int x)
{
	this->pozX = x;
}

void Element::setPozY(int y)
{
	this->pozY = y;
}

void Element::setOrientare(int orient)
{
	this->orientare = orient;
}