#pragma once
#include <string>
class Illness
{
public:
	Illness(std::string type, std::string name, int stadium);
	Illness();

	void changeStadium(int stad);
	std::string getName() const;
private:
	std::string type;
	std::string name;
	int stadium;
	bool healChances;
};

