#pragma once
#include "People.h"
class People;
class Lunds
{
public:
	Lunds(int healthyPart,int illPArt,int capacity);
	Lunds(int healthyPart, int illPArt, People& per);
	Lunds();

	void setHealthy(int h);
	void setIll(int i);
	void setCapacity(Person per, int age);

	int getHealthy();
	int getIll();
	int getCapacity();
private:
	int healthyPart;
	int illPArt;
	int capacity;
};

