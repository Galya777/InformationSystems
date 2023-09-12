#pragma once
#include "Jedi.h"
#include <iostream>
#include <cmath>
#include <vector>
const int MAX = 1000;
class Planet
{
public:
	Planet(const char* name);
	Planet();
	Planet(const Planet& other);
	Planet operator=(const Planet& other);
	~Planet();

	char* getName() const;
	void setName(const char* name);
	int getSize() const;

	void addJedi(Jedi& jedi);
	void removeJedi(int possition);
	Jedi getJedi(int position);
	Jedi getByName(const char* name);
	int getPosition(const char* name);
	bool isJediHere(const char* name);
	Jedi getStrongest();
	Jedi getYoungest(int rank, int counter=0);
	const char* getMostUsedColor(int rank) const;
	void sortByRank();
	void sortByName();

	virtual void readFromFile(std::ifstream& file);
	virtual void writeToFile(std::fstream& file);
private:
	void swap(Jedi& left, Jedi& right);
	void sortByPower();
	void sortByAge();

	char* name;
	std::vector<Jedi>jedies;
	size_t size = 0;
};

