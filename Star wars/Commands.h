#pragma once
#pragma warning(disable:4996)
#include <fstream>
#include <cstring>
#include <vector>
#include "Planet.h"
const int MAX_CONTENT = 100;
const int MAX_FILE = 100;
class Commands
{
public:
	Commands(const char* com);
	Commands();
	void open();
	void close();
	void save();
	void saveAs();

	void addPlanet(const char* name);
	void createJedi(const char* planet, const char* name, int rank, int age, const char* color, double power);
	void removeJedi(const char* name, const char* planet);
	void promoteJedi(const char* name, double multiplier);
	void demoteJedi(const char* name, double multiplier);
	void get_Strongest_Jedi(const char* planet);
	void get_Yoingest_Jedi(const char* planet, int rank);
	const char* get_most_used_saber_color(const char* planet, int rank);
	void printJedi(const char* planet);
	void printPlanet(const char* jedi);
	void twoPlanets(const char* first, const char* second);

	void run();
private:
	Planet getByName(const char* name);
	Jedi getJediByName(const char* name);
	bool excistingJedi(const char* name);
	bool excistingPlanet(const char* planet);
	int getJediPosition(const char* name);
	int getPlanetPosition(const char* name);

	std::string command;
	std::fstream oldFile;
	std::ifstream newFile;
	char file[MAX_FILE];
	std::vector<Planet>planets;
	std::vector<Jedi>jedies;
};

