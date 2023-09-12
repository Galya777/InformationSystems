#include "Commands.h"
#include <iostream>

Commands::Commands(const char* com)
{

}

Commands::Commands()
{
	command=" ";
	planets.push_back(Planet());
	jedies.push_back(Jedi());
}

void Commands::open()
{
	std::cin >> file;
	newFile.open(file);
	if (newFile) {
		char arr[MAX_CONTENT];
		while (!newFile.eof()) {
			newFile.getline(arr, MAX_CONTENT);
			std::cout << arr << std::endl;
		}
		planets.at(0).readFromFile(newFile);
	}
	else {
		oldFile.open(file, std::ios::app);
		oldFile << "New File";
	}
	std::cout << "File successfully opened!" << std::endl;
	}

void Commands::close()
{
	oldFile.close();
	newFile.close();
	std::cout << "File successfully closed!" << std::endl;
}

void Commands::save()
{
	char* buffer;
	long size;

	std::ifstream infile(file, std::ifstream::binary);
	std::ofstream outfile(file, std::ofstream::binary);
	infile.seekg(0, std::ifstream::end);
	size = infile.tellg();
	infile.seekg(0);
	buffer = new char[size];
	infile.read(buffer, size);
	outfile.write(buffer, size);
	delete[] buffer;

	outfile.close();
	infile.close();
	std::cout << "File successfully saved!" << std::endl;
}

void Commands::saveAs()
{
	char* buffer;
	long size;
	char path[MAX_FILE];
	std::cout << "Enter the path: ";
	std::cin >> path;
	std::ifstream infile(file, std::ifstream::binary);
	std::ofstream outfile(path, std::ofstream::binary);
	infile.seekg(0, std::ifstream::end);
	size = infile.tellg();
	infile.seekg(0);
	buffer = new char[size];
	infile.read(buffer, size);
	outfile.write(buffer, size);
	delete[] buffer;
	outfile.close();
	infile.close();
	std::cout << "File successfully saved!" << std::endl;
}

void Commands::addPlanet(const char* name)
{
	planets.push_back(Planet(name));
	std::cout << "Planet added successfully!"<<std::endl;
}

void Commands::createJedi(const char* planet, const char* name, int rank, int age, const char* color, double power)
  {  
	Jedi newOne(name, rank, age, color, power);
	if (excistingJedi(name) == false) {
		if (excistingPlanet(planet) == true) {
			int pos = getPlanetPosition(planet);
			planets.at(pos).addJedi(newOne);
				std::cout << name << " successfully added to " << planet << std::endl;
				jedies.push_back(newOne);
			
		}else {
			std::cout << "Planet is not excisting!" << std::endl;
		}
	}
	else {
		std::cout << "This jedi is living on this or another planet. We cannot move him!"<<std::endl;
	}
}

void Commands::removeJedi(const char* name, const char* planet)
{
	Planet pl = getByName(planet);
	if (excistingPlanet(planet) == true) {
		if (pl.isJediHere(name) == true) {
			int position = pl.getPosition(name);
			pl.removeJedi(position);
			std::cout << name << " successfully removed by " << *planet<<std::endl;
			int jediPos = getJediPosition(name);
			jedies.erase(jedies.begin() + jediPos);
		}
		else {
			std::cout << "This jedi is not living here!"<<std::endl;
		}
	}
}

void Commands::promoteJedi(const char* name, double multiplier)
{
	if (excistingJedi(name) == true) {
		Jedi jedi = getJediByName(name);
		jedi.setRank(jedi.getRank()+1);
		jedi.setPower(jedi.getPower() + multiplier * jedi.getPower());
		std::cout << name << " promoted successfully to "; jedi.printRank();
		 std::cout<<std::endl;
	}
	else {
		std::cout << "Jedi is not excisting!" << std::endl;
	}
}

void Commands::demoteJedi(const char* name, double multiplier)
{
	if (excistingJedi(name) == true) {
		Jedi jedi = getJediByName(name);
		jedi.setRank(jedi.getRank() - 1);
		jedi.setPower(jedi.getPower() - multiplier * jedi.getPower());
		std::cout << name << " demoted successfully to "; jedi.printRank();
		std::cout << std::endl;
	}
	else {
		std::cout << "Jedi is not excisting!" << std::endl;
	}
}

void Commands::get_Strongest_Jedi(const char* planet)
{
	int pos = getPlanetPosition(planet);
	planets.at(pos).getStrongest().printJedi();
}

void Commands::get_Yoingest_Jedi(const char* planet, int rank)
{
	int pos = getPlanetPosition(planet);
	planets.at(pos).getYoungest(rank,0).printJedi();
}

const char* Commands::get_most_used_saber_color(const char* planet, int rank)
{
	int pos = getPlanetPosition(planet);
	return planets.at(pos).getMostUsedColor(rank);
}

void Commands::printJedi(const char* planet)
{
	int pos = getPlanetPosition(planet);
	
	for (int i = 0; i < planets.at(pos).getSize(); ++i) {
		planets.at(pos).getJedi(i).printJedi();
	}
}

void Commands::printPlanet(const char* jedi)
{
	if (excistingJedi(jedi) == true) {
		Jedi jed = getJediByName(jedi);
		jed.printJedi();
		for (int i = 0; i < planets.size(); ++i) {
			if (planets.at(i).isJediHere(jedi) == true) {
              std::cout << "This jedi is living on "<<planets.at(i).getName()<<std::endl;
			}
		}
		
	}
	else {
		std::cout << "Jedi is not excisting!" << std::endl;
	}
}

void Commands::twoPlanets(const char* first, const char* second)
{
	if (excistingPlanet(first) == true && excistingPlanet(second) == true) {
		Planet pl1(getByName(first));
		Planet pl2(getByName(second));
		std::cout << first << ":" << std::endl;
		for (int i = 0; i < pl1.getSize(); ++i) {
			pl1.getJedi(i).printJedi();
		}
		std::cout << second << ":" << std::endl;
		for (int i = 0; i < pl2.getSize(); ++i) {
			pl2.getJedi(i).printJedi();
		}

	}else {
		std::cout << "One of these planets is not excisting!" << std::endl;
	}
}

void Commands::run()
{
	char planetName[100];
		char jediName[100];
		int rank, age;
		char color[100];
		double power;
	do {
		std::cout << "Enter your command: ";
		std::cin >> command;
		if (command == "open") {
			open();

		}
		else if (command == "close") {
			close();
		}
		else if (command == "save") {
			for (int i = 0; i < planets.size(); ++i) {
				planets.at(i).writeToFile(oldFile);
			}
			save();
		}
		else if (command == "save as") {
			for (int i = 0; i < planets.size(); ++i) {
				planets.at(i).writeToFile(oldFile);
			}
			saveAs();
		}
		else if (command == "addP") {
			std::cout << "Enter the name of the planet: ";
			std::cin.ignore();
			std::cin.getline(planetName,1000);
			addPlanet(planetName);
		}
		else if (command == "createJ") {
			std::cout << "Enter the name of the planet: ";
			std::cin.ignore();
			std::cin.getline(planetName, 1000);
			std::cout << "Enter the name of the jedi: ";
			std::cin.getline(jediName, 1000);
			std::cout << "Enter the rank of the jedi: ";
			std::cin>>rank;
			std::cout << "Enter the age of the jedi: ";
			std::cin >> age;
			std::cout << "Enter the color of his saber: ";
			std::cin.ignore();
			std::cin.getline(color, 1000);
			std::cout << "Enter the power of the jedi: ";
			std::cin>>power;
			createJedi(planetName, jediName, rank, age, color, power);
		}
		else if (command == "remove") {
			std::cout << "Enter the name of the planet: ";
			std::cin.getline(planetName, 1000);
			std::cout << "Enter the name of the jedi: ";
			std::cin.getline(jediName, 1000);
			removeJedi(jediName, planetName);
		}
		else if (command == "promote") {
			std::cout << "Enter the name of the jedi: ";
			std::cin.ignore();
			std::cin.getline(jediName, 1000);
			std::cout << "Enter the power of the jedi: ";
			std::cin >> power;
			promoteJedi(jediName, power);

		}
		else if (command == "demote") {
			std::cout << "Enter the name of the jedi: ";
			std::cin.ignore();
			std::cin.getline(jediName, 1000);
			std::cout << "Enter the power of the jedi: ";
			std::cin >> power;
			demoteJedi(jediName, power);
		}
		else if (command == "strongest") {
			std::cout << "Enter the name of the planet: ";
			std::cin.ignore();
			std::cin.getline(planetName, 1000);
			get_Strongest_Jedi(planetName);
		}
		else if (command == "youngest") {
			std::cout << "Enter the name of the planet: ";
			std::cin.ignore();
			std::cin.getline(planetName, 1000);
			std::cout << "Enter the rank of the jedi: ";
			std::cin >> rank;
			get_Yoingest_Jedi(planetName,rank);
		}
		else if (command == "sabber") {
			std::cout << "Enter the name of the planet: ";
			std::cin.ignore();
			std::cin.getline(planetName, 1000);
			std::cout << "Enter the rank of the jedi: ";
			std::cin >> rank;
			std::cout<<get_most_used_saber_color(planetName, rank);
		}
		else if (command == "sabberG") {
			std::cout << "Enter the name of the planet: ";
			std::cin.ignore();
			std::cin.getline(planetName, 1000);
			std::cout<<get_most_used_saber_color(planetName, GRAND_MASTER);
		}
		else if (command == "printJ") {
			std::cout << "Enter the name of the planet: ";
			std::cin.ignore();
			std::cin.getline(planetName, 1000);
			printJedi(planetName);
		}
		else if (command == "printP") {
			std::cout << "Enter the name of the jedi: ";
			std::cin.ignore();
			std::cin.getline(jediName, 1000);
			printPlanet(jediName);
		}
		else if (command == "twoplanets") {
			std::cout << "Enter the name of the first planet: ";
			std::cin.ignore();
			std::cin.getline(planetName, 1000);
			std::cout << "Enter the name of the second planet: ";
			std::cin.ignore();
			std::cin.getline(jediName, 1000);
			twoPlanets(planetName, jediName);
		}
		else if (command != "exit") {
			std::cout << "Invalid command! Try again!" << std::endl;
		}
	} while (command != "exit");
	
}

Planet Commands::getByName(const char* name)
{
	for (int i = 0; i < planets.size(); ++i) {
		if (strcmp(planets.at(i).getName(), name) == 0) {
			return planets.at(i);
		}
	}
	
	return Planet();
}

Jedi Commands::getJediByName(const char* name)
{
	for (int i = 0; i < jedies.size(); ++i) {
		if (strcmp(jedies.at(i).getName(), name) == 0) {
			return jedies.at(i);
		}
	}
	return Jedi();
}

bool Commands::excistingJedi(const char* name)
{
	for (int i = 0; i < jedies.size(); ++i) {
		if (strcmp(jedies.at(i).getName(), name) == 0) {
			return true;
		}
	}
	return false;
}

bool Commands::excistingPlanet(const char* planet)
{
	for (int i = 0; i < planets.size(); ++i) {
		if (strcmp(planets.at(i).getName(), planet) == 0) {
			return true;
		}
	}
	return false;
}

int Commands::getJediPosition(const char* name)
{
	for (int i = 0; i < jedies.size(); ++i) {
		if (strcmp(jedies.at(i).getName(), name) == 0) {
			return i;
		}
	}
	return -1;
}

int Commands::getPlanetPosition(const char* name)
{
	for (int i = 0; i < planets.size(); ++i) {
		if (strcmp(planets.at(i).getName(), name) == 0) {
			return i;
		}
	}
	return -1;
}



	

		
	
