#pragma once
#include "Dinasour.h"
/**
 * @class FlyingDinos
 * child of Dinasour
 * describing flying dinasours
*/
class FlyingDino:public Dinasour
{
public:

	/**
	 * @brief constructor
	 * @param name
	 * @param sex
	 * @param category
	*/
	FlyingDino(std::string name, std::string sex, std::string category);

	/**
	 * @brief type
	 * @return type of the dinasour
	*/
	Type type() const { return Type::FLYING; }

	/**
	 * @brief era
	 * @return the era of the dinosaur
	 * * According to encyclopedia it is constant for this type
	*/
	Era get_era() const { return Era::TRIAS; };

	/**
	 * @brief food
	 * @return the food dinasors are eating
	*/
	Food get_feed() const { return Food::MEAT; };

	/**
	 * @brief
	 * @param stream
	 * reads dinosaurs from file
	*/
	void read_from_file(std::ifstream& stream);

	/**
	 * @brief
	 * @return copy of the class to dinosaurs
	*/
	Dinasour* clone() const { return new FlyingDino(*this); };

	/**
	 * @brief
	 * @param filename
	 * prints information in a file
	*/
	void print(const char* filename);

};

