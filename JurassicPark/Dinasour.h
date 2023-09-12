#pragma once
#include <string>
#include <iostream>
#include <fstream>
/**
 * @brief 
 * an enum
 * the era of the dinosaur
*/
enum Era {
	TRIAS, 
	KREDA, 
	URA
};
/**
 * @brief 
 * an enum
 * what they are eating 
*/
enum Food {
	GRASS,
	MEAT,
	FISH
};
/**
 * @brief 
 * type of the dinosaur
*/
enum Type {
	FLYING, 
	WATER,
	HEBRIVOROUS,
	CARNIVOROUS
};
/**
 * @class Dinasour
 * base class for describing dinasours
*/
class Dinasour
{
public: 
	/**
	 * @brief 
	 * @param name 
	 * @param gender 
	 * @param type 
	 * constructor
	*/
	 Dinasour(std::string name, std::string gender, Type type);
	/**
	 * @brief 
	 * default constructor
	*/
     Dinasour();

	/**
	 * @brief 
	 * @param name 
	 * setter for name
	*/
	void setName(std::string name);
	/**
	 * @brief 
	 * @param sex 
	 * setter for gender
	*/
	void setGender(std::string sex);
	/**
	 * @brief 
	 * @param type 
	 * setter for type
	*/
	void setType(Type type);

	/**
	 * @brief 
	 * @return name
	*/
	std::string getName() const;
	/**
	 * @brief 
	 * @return gender
	*/
	std::string getGender() const;

	/**
	 * @brief 
	 * @return string of the type
	*/
	std::string getTypeToText(Type t) const;
	/**
	 * @brief 
	 * @return type
	*/
	Type getType() const;

	/**
	 * @brief 
	 * @return the era of the dinasour
	*/
	Era getEra() const;

	/**
	 * @brief 
	 * @return the type based on a text
	*/
	Type getTypeFromText(std::string cat) const;
	/**
	 * @brief 
	 * @param file 
	 * reads from file
	*/
	void read(std::istream& file);
	/**
	 * @brief 
	 * @param file 
	 * writes to file
	*/
	void write(std::ostream& file);


protected:
	std::string name;
	std::string gender;
	Type type;

	/**
	 * @brief 
	 * @param gender 
	 * @return 
	 * check if gender is valid value
	*/
	static bool validGender(std::string gender);
	
};

