#include "Zoo.h"

int Zoo::getCellSizeAt(int index) const
{
	return cages.at(index).getSize();
}

int Zoo::getFreeSpaceAt(int index) const
{
	return cages.at(index).getFreeSpace();
}

Era Zoo::getEraAt(int index, int cage) const
{
    return cages.at(index).getEraAt(cage);
}

Climate Zoo::getClimateAt(int index) const
{
    return cages.at(index).getClimate();
}

Dinasour Zoo::getDinoAt(int index1, int index2) const
{
    return cages.at(index1).getDinoAt(index2);
}

void Zoo::readFromFile(const char* filename)
{
	int cellsNum = 0;
	std::ifstream iFile(filename, std::ios::binary);
	iFile.read((char*)&cellsNum, sizeof(int));
	if (cellsNum == 0)
		return;
	int grass, meat, fish;
	iFile.read((char*)&grass, sizeof(int));
	iFile.read((char*)&meat, sizeof(int));
	iFile.read((char*)&fish, sizeof(int));
	foodStorage[0] = grass;
	foodStorage[1] = meat;
	foodStorage[2] = fish;
	cages.push_back(Cage());
	for (unsigned i = 0; i < cages.size(); i++)
	{
		int size, freeSpace;
		Era era;
		Climate climate;
		iFile.read((char*)&size, sizeof(int));
		iFile.read((char*)&freeSpace, sizeof(int));
		iFile.read((char*)&climate, sizeof(Climate));
		Cage cell(size, climate);
		for (int j = 0; j < size - freeSpace; j++)
		{
			int nameLen, kindLen;
			bool array[4], is0, is1, is2, is3;
			Era dinoEra;
			Food food;
			std::string sex;

			iFile.read((char*)&nameLen, sizeof(int));
			char* name = new char[nameLen];
			iFile.read(name, sizeof(char) * nameLen);
			iFile.read((char*)&kindLen, sizeof(int));
			Type kind;
			iFile.read((char*)&kind, sizeof(Type) * kindLen);

			iFile.read((char*)&dinoEra, sizeof(Era));
			iFile.read((char*)&food, sizeof(Food));
			iFile.read((char*)&sex, sizeof(sex));
			iFile.read((char*)&is0, sizeof(bool));
			iFile.read((char*)&is1, sizeof(bool));
			iFile.read((char*)&is2, sizeof(bool));
			iFile.read((char*)&is3, sizeof(bool));
			array[0] = is0;
			array[1] = is1;
			array[2] = is2;
			array[3] = is3;
			Dinasour d(name, sex, kind);
			cell.addDino(d, d.getEra());
			delete[] name;
		}
		cages.at(i) = cell;
	}
	iFile.close();
}

Zoo::Zoo()
{
	cages.push_back(Cage()); 
	for (int i = 0; i < 3; i++)
		foodStorage[i] = 0;
}

void Zoo::addDino(Dinasour dino)
{
	int index = 0;
	Climate climate;
	if (dino.getType()==Type::WATER)
		climate = water;
	else
		if (dino.getType() == Type::FLYING)
			climate = air;
		else
			climate = earth;
	bool flag = false;
		if (climate == cages[index].getClimate() && dino.getEra() == cages.at(index).getDinoAt(index).getEra())
			cages[index].addDino(dino, dino.getEra());
		    
		index++;
	if (!flag)
	{
		int size;
		std::cout << "Size of the cell:" << std::endl;
		std::cin >> size;
		if (size != 1 && size != 3 && size != 10)
			size = 1;
		Cage cell(size, climate);
		cell.addDino(dino, dino.getEra());
		addCell(cell);
	}
}

void Zoo::addCell(const Cage& cell)
{
	cages.push_back(cell);
}

void Zoo::removeDino(const char* name)
{
	bool removed = false;
	for (unsigned i = 0; i < cages.size(); ++i) {
		for (int j = 0; j < cages.at(i).getSize(); ++j) {
			if (strcmp(name, cages.at(i).getDinoAt(j).getName().c_str()) == 0) {
				cages.at(i).removeDino(name);
				removed = true;
			}
		}
	}
	if (removed == false) {
		std::cout << "Dinasour with this name is not excisting!";
	}
}

void Zoo::addFood(const char* food, int quantity)
{
	if (!strcmp(food, "grass"))
		foodStorage[0] += quantity;
	else
		if (!strcmp(food, "meat"))
			foodStorage[1] += quantity;
		else
			if (!strcmp(food, "fish"))
				foodStorage[2] += quantity;
}

int Zoo::getGrass() const
{
	return foodStorage[0];
}

int Zoo::getMeat() const
{
	return foodStorage[1];
}

int Zoo::getFish() const
{
	return foodStorage[2];
}

void saveToFile(const char* filename, const Zoo& zoo)
{
	std::ofstream oFile(filename, std::ios::binary);
	int grass = zoo.getGrass();
	int meat = zoo.getMeat();
	int fish = zoo.getFish();
	oFile.write((char*)&grass, sizeof(int));
	oFile.write((char*)&meat, sizeof(int));
	oFile.write((char*)&fish, sizeof(int));
	for (unsigned i = 0; i < zoo.cages.size(); i++)
	{
		int size = zoo.getCellSizeAt(i), freeSpace = zoo.getFreeSpaceAt(i);
		Era era = zoo.getEraAt(i,i);
		Climate climate = zoo.getClimateAt(i);
		oFile.write((char*)&size, sizeof(int));
		oFile.write((char*)&freeSpace, sizeof(int));
		oFile.write((char*)&era, sizeof(Era));
		oFile.write((char*)&climate, sizeof(Climate));
		for (int j = 0; j < size - freeSpace; j++)
		{
			Dinasour dino = zoo.getDinoAt(i, j);
			int nameLen = strlen(dino.getName().c_str()) + 1;
			char* dinoName = new char[nameLen];
			strcpy(dinoName, dino.getName().c_str());
			oFile.write((char*)&nameLen, sizeof(int));
			oFile.write((char*)dinoName, sizeof(char) * nameLen);

			int kindLen = strlen(dino.getTypeToText(dino.getType()).c_str()) + 1;
			char* dinoKind = new char[kindLen];
			strcpy(dinoKind, dino.getTypeToText(dino.getType()).c_str());
			oFile.write((char*)&kindLen, sizeof(int));
			oFile.write((char*)dinoKind, sizeof(char) * kindLen);

			Era dinoEra = dino.getEra();
			std::string sex = dino.getGender();
			oFile.write((char*)&dinoEra, sizeof(Era));
			oFile.write((char*)&sex, sizeof(sex));

			delete[] dinoName;
			delete[] dinoKind;
		}
	}
}
