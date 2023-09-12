#include "FlyingDino.h"

FlyingDino::FlyingDino(std::string name, std::string sex, std::string category)
{
	this->name = name;
	if (validGender(sex) == true) {
		this->gender = sex;
	}
	else {
		std::cout << "Invalid gender!";
	}
	setType(getTypeFromText(category));
}

void FlyingDino::read_from_file(std::ifstream& stream)
{
}

void FlyingDino::print(const char* filename)
{
	std::ofstream ofile(filename);
	if (!ofile) {
		std::cerr << "The file couldn't be opened.\n";
	}
	std::cout << "Water Dinosaur: " << std::endl;
	Dinasour::write(ofile);

	ofile.close();
}
