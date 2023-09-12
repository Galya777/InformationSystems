enum Person {
	UNKNOWN = -1,
	SMOKER,
	SPORTPLAYER
};
#pragma once
#include <string>
#include <vector>
#include "Lunds.h"
#include "Illness.h"
#include "Lunds.h"
class Lunds;

class People
{
public:
	People(std::string name, int age, Person type);
	People();
	Person getType();
	int getAge();
	std::string getName() const;

	void makeLunds();
	void addIllness(Illness illness);
	void heal(std::string name);
	virtual void changeCapacity(int cig);
protected:
	std::string name;
	int age;
	Lunds* lunds;
	std::vector <Illness> illnesses;
	Person typ;
};

