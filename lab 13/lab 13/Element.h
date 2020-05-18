#pragma once
class Element
{
protected:
	int pozX;
	int pozY;
	int orientare;
public:
	Element();
	~Element();
	int getPozX();
	int getPozY();
	int getOrientare();
	void setPozX(int);
	void setPozY(int);
	void setOrientare(int);
};