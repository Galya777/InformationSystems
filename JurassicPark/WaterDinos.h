#pragma once
#include "Dinasour.h"
#include <fstream>
/**
 * @class WaterDinos
 * child of Dinasour
 * describing water dinasours
*/
class WaterDinos: public Dinasour
{
public: 

	/**
	 * @brief constructor
	 * @param name 
	 * @param sex 
	 * @param category 
	*/
	WaterDinos(std::string name, std::string sex, std::string category);
	/**
	 * @brief type
	 * @return type of the dinasour
	*/
	Type type() const { return Type::WATER; }
	/**
	 * @brief era
	 * @return the era of the dinosaur
	 * * According to encyclopedia it is constant for this type
	*/
	Era get_era() const { return Era::KREDA; };
	/**
	 * @brief food
	 * @return the food dinasors are eating
	*/
	Food get_feed() const { return Food::FISH; };

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
	Dinasour* clone() const { return new WaterDinos(*this); };

	/**
	 * @brief 
	 * @param filename 
	 * prints information in a file
	*/
	void print(const char* filename);
};

