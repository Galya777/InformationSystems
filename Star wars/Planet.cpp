#include "Planet.h"

Planet::Planet(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	jedies.push_back(Jedi());
	size++;
}

Planet::Planet()
{
	this->name = new char[1];
	strcpy(this->name, "");
	jedies.push_back(Jedi());
	size++;
}

Planet::Planet(const Planet& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

Planet Planet::operator=(const Planet& other)
{
	if (this != &other) {
		delete[] name;
		strcpy(name, other.name);
	}
	return *this;
}

Planet::~Planet()
{
	delete[] name;
}

char* Planet::getName() const
{
	return name;
}

void Planet::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int Planet::getSize() const
{
	return size;
}

void Planet::addJedi(Jedi& jedi)
{
	jedies.push_back(jedi);
	size++;
}

void Planet::swap(Jedi& left, Jedi& right) {
	Jedi temp(left);
	left.operator=(right);
	right.operator=(temp);
}

void Planet::removeJedi(int possition)
{
	jedies.erase(jedies.begin() + possition);
}

Jedi Planet::getJedi(int position)
{
	return jedies.at(position);
}

Jedi Planet::getByName(const char* name)
{
	for (int i = 0; i < size; ++i) {
		if (strcmp(jedies.at(i).getName(), name) == 0) {
			return jedies.at(i);
		}
	}
	std::cout << "No, this jedi is not living in this planet"<<std::endl;
	return Jedi();
}

int Planet::getPosition(const char* name)
{
	for (int i = 0; i < size; ++i) {
		if (strcmp(jedies.at(i).getName(), name) == 0) {
			return i;
		}
	}
	std::cout << "No, this jedi is not living in this planet";
	return -1;
}

bool Planet::isJediHere(const char* name)
{
	for (int i = 0; i < size; ++i) {
		if (strcmp(jedies.at(i).getName(), name) == 0) {
			return true;
		}
	}
	std::cout << "No, this jedi is not living in this planet";
	return false;
}

Jedi Planet::getStrongest()
{
	sortByPower();
	return jedies.at(0);
}

Jedi Planet::getYoungest(int rank, int counter)
{
	sortByAge();
	if (counter >= size) {
		std::cout << "No jedi with this rank on this planet!" << std::endl;
		return Jedi();
	}
	if (jedies.at(counter).getRank() == rank) {
		return jedies.at(counter);
	}
	
	return getYoungest(rank, counter + 1);
	
}

const char* Planet::getMostUsedColor(int rank) const
{
	std::vector<Jedi>thisRank;
	int color1 = 0, color2 = 0, color3 = 0;
	for (int i = 0; i < jedies.size(); ++i) {
		if (jedies.at(i).getRank() == rank) {
			thisRank.push_back(jedies.at(i));
		}
	}
	for (int i = 0; i < thisRank.size() - 1; ++i) {
		if (strcmp(thisRank.at(i).getColor(), "red") == 0) {
			color1++;
		}
		else if (strcmp(thisRank.at(i).getColor(), "blue") == 0) {
			color2++;
		}
		else if (strcmp(thisRank.at(i).getColor(), "green") == 0) {
			color3++;
		}
	}
	int maxImum = std::max(std::max(color1, color2), color3);
	if (maxImum != 0) {
		if (maxImum == color1) {
			return "red";
		}
		else if (maxImum == color2) {
			return "blue";
		}
		else if (maxImum == color3) {
			return "green";
		}
	}
	else {
		std::cout << "No jedi with this rank is living here!";
		return nullptr;
	}
}

void Planet::sortByRank()
{
	size_t i, j, min;

	for (i = 0; i < size; i++) {
		min = i;

		for (j = i + 1; j < size; j++) {
			if (jedies.at(j).getRank() < jedies.at(min).getRank()) {
				min = j;
			}
			else if (jedies.at(j).getRank() == jedies.at(min).getRank()) {
				if (strcmp(jedies.at(j).getName(), jedies.at(min).getName()) < 0) {
					min = j;
				}
			}
		}

		if (min != i) {
			swap(jedies.at(min), jedies.at(i));
		}

	}
}

void Planet::sortByName()
{
	size_t i, j, min;

	for (i = 0; i < size; i++) {
		min = i;

		for (j = i + 1; j < size; j++) {

			if (strcmp(jedies.at(j).getName(), jedies.at(min).getName()) < 0) {
				min = j;
			}
		}
		if (min != i) {
			swap(jedies.at(min), jedies.at(i));
		}

	}
}

void Planet::readFromFile(std::ifstream& file)
{
	int rCounter = 0;
	char* buffer = new char[MAX];
	while (file)
	{
		file.getline(buffer, MAX);
		Planet(buffer);
		buffer = new char[MAX];
		rCounter++;
	}
	delete[] buffer;
}

void Planet::writeToFile(std::fstream& file)
{
	file << name << '/n';
	for (int i = 0; i < jedies.size(); ++i) {
		jedies.at(i).writeToFile(file);
	}
	file << '/n';
}

void Planet::sortByAge()
{
	size_t i, j, min;

	for (i = 0; i < size; i++) {
		min = i;

		for (j = i + 1; j < size; j++) {
			if (jedies.at(j).getAge() < jedies.at(min).getAge()) {
				min = j;
			}
			else if (jedies.at(j).getAge() == jedies.at(min).getAge()) {
				if (strcmp(jedies.at(j).getName(), jedies.at(min).getName()) < 0) {
					min = j;
				}
			}
		}

		if (min != i) {
			swap(jedies.at(min), jedies.at(i));
		}

	}
}

void Planet::sortByPower()
{
	size_t i, j, max;

	for (i = 0; i < size; i++) {
		max = i;

		for (j = i + 1; j < size; j++) {
			if (jedies.at(j).getPower() > jedies.at(max).getPower()) {
				max = j;
			}
		}

		if (max != i) {
			swap(jedies.at(max), jedies.at(i));
		}

	}

}

