#include "Manager.h"

Manager::Manager()
{
	zoo.readFromFile("Zoo.txt");
}

void Manager::menu()
{
	system("cls");
	cout << "1. Add dinosaur" << endl;
	cout << "2. Add cell" << endl;
	cout << "3. Remove dinosaur" << endl;
	cout << "4. Store food" << endl;
	cout << "5. Exit" << endl;
	int option;
	cin >> option;
	if (option == 1)
	{
		addDino();
		menu();
	}
	if (option == 2)
	{
		addCell();
		menu();
	}
	if (option == 3)
	{
		removeDino();
		menu();
	}
	if (option == 4)
	{
		store();
		menu();
	}
	else
		save();
}

void Manager::addDino()
{
	system("cls");
	cout << "Enter name " << endl;
	std::string name;
	cin>>name;
	system("cls");
	cout << "Enter kind " << endl;
	std::string kind;
	cin>>kind;
	cout << "Enter gender " << endl;
	std::string sex;
	cin >> sex;
	system("cls");
	Era era;
	Food food;
	bool classification[4];
	system("cls");

	cout << "Food:" << endl;
	cout << "1. Grass" << endl;
	cout << "2. Meat" << endl;
	cout << "3. Fish" << endl;
	int option;
	cin >> option;
	if (option == 1)
		food = Food::GRASS;
	if (option == 2)
		food = Food::MEAT;
	else
		food = Food::FISH;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " herbivorous?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[0] = true;
	else
		classification[0] = false;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " carnivorous?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[1] = true;
	else
		classification[1] = false;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " flying?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[2] = true;
	else
		classification[2] = false;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " aquous?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[3] = true;
	else
		classification[3] = false;
	Dinasour d= Dinasour();
	d.setName(name);
	d.setGender(sex);
	d.setType(d.getTypeFromText(kind));
	zoo.addDino(d);
}

void Manager::addCell()
{
	Cage cell;
	zoo.addCell(cell);
}

void Manager::removeDino()
{
	std::string name;
	cin>>name;
	zoo.removeDino(name.c_str());
}

void Manager::store()
{
	system("cls");
	int quantity;
	cout << "How much grass do you want to add?" << endl;
	cin >> quantity;
	zoo.addFood("grass", quantity);
	cout << "How much meat do you want to add?" << endl;
	cin >> quantity;
	zoo.addFood("meat", quantity);
	cout << "How much fish do you want to add?" << endl;
	cin >> quantity;
	zoo.addFood("fish", quantity);
}

void Manager::save()
{
	saveToFile("Zoo.txt", zoo);
}
