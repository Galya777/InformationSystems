#include "Lunds.h"

Lunds::Lunds(int healthyPart, int illPArt, int capacity)
{
	this->healthyPart = healthyPart;
	this->illPArt = illPArt;
	this->capacity = capacity;
}

Lunds::Lunds(int healthyPart, int illPArt, People& per)
{
	this->healthyPart = healthyPart;
	this->illPArt = illPArt;
	if (per.getType() == SMOKER) {
		capacity = per.getAge()+ 3500;
	}
	else if (per.getType() == SPORTPLAYER) {
		capacity = per.getAge()*1600 + 3500;
	}else {
		capacity = 3500; //this is the average capacity of a human
	}
}

Lunds::Lunds()
{
	healthyPart = 0;
	illPArt = 0;
	capacity = 0;
}

void Lunds::setHealthy(int h)
{
	healthyPart = h;
}

void Lunds::setIll(int i)
{
	illPArt = i;
}

void Lunds::setCapacity(Person per, int age)
{
	if (per == SMOKER) {
		capacity = age+ 3500;
	}
	else if (per == SPORTPLAYER) {
		capacity = age*1600 + 3500;
	}else {
		capacity = 3500; //this is the average capacity of a human
	}
}

int Lunds::getHealthy()
{
	return healthyPart;
}

int Lunds::getIll()
{
	return illPArt;
}

int Lunds::getCapacity()
{
	return capacity;
}
