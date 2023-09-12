#pragma once
#include <string>
#include "Dinasour.h"
#include <vector>
/**
 * @brief 
 * the climate of the cages
*/
enum Climate { earth, air, water };
/**
 * @brief 
 * capacity of cages
*/
const int values[3] = { 1, 3, 10 };
/**
 * @brief 
 * this class represents the cage
*/
class Cage
{
public:
	/**
	 * @brief 
	 * @param size 
	 * @param climat 
	 * constructor
	*/
	Cage(int size, Climate climat);
	/**
	 * @brief 
	 * default constructor
	*/
	Cage();
	/**
	 * @brief 
	 * @param other 
	 * copy constructor
	*/
	Cage(const Cage& other);
	
	/**
	 * @brief 
	 * @param dino 
	 * @param era 
	 * adding a dinasour and its era
	*/
	void addDino(Dinasour dino, Era era);

	/**
	 * @brief 
	 * @param name 
	 * removing a dinasour by its name
	*/
	void removeDino(std::string name);

	/**
	 * @brief 
	 * @return climate
	*/
	Climate getClimate() const;
	
	/**
	 * @brief 
	 * @param index 
	 * @return era
	*/
	Era getEraAt(int index) const;
	
	/**
	 * @brief 
	 * @return size
	*/
	int getSize() const;

	/**
	 * @brief 
	 * @return freeSpace
	*/
	int getFreeSpace() const;
	/**
	 * @brief 
	 * @param index 
	 * @return dino by index
	*/
	Dinasour getDinoAt(int index) const;

protected:
	
	std::vector<Dinasour> dinos;
	std::vector<Era> eras;
	int reservedPlaces = 0;

	int size;
	Climate climat;
	
	int spaceLeft;
};

