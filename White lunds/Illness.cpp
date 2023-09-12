#include "Illness.h"
#include <iostream>

Illness::Illness(std::string type, std::string name, int stadium)
{
	this->type = type;
	this->name = name;
	changeStadium(stadium);
}

Illness::Illness()
{
	type = "";
	name = "";
	
}

void Illness::changeStadium(int stad)
{
	stadium = stad;
	while (stadium > 4) {
		std::cout << "Invalid stadium!" << std::endl;
		std::cin >> stad;
	}
	if (stad <= 2) {
		healChances = true;
	}
	else {
		healChances = false;
	}
}

std::string Illness::getName() const
{
	return name;
}
