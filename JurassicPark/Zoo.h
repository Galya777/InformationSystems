#pragma once
#include "Cage.h"
#include "WaterDinos.h"
#include "FlyingDino.h"
#include "Vegans.h"
#include "EatingMeet.h"
#include <vector>
#pragma warning(disable:4996)
/**
 * @brief 
 * this class is representing the zoo which has array of cells and food 
*/
class Zoo
{
public:
	/**
	 * @brief 
	 * default constructor
	*/
	Zoo();

	/**
	 * @brief 
	 * @param dino 
	 * adding a dinasour 
	*/
	void addDino(Dinasour dino);

	/**
	 * @brief 
	 * @param cell 
	 * adding a new cage 
	*/
	void addCell(const Cage& cell);

	/**
	 * @brief 
	 * @param name 
	 * removing a dinasour by name 
	*/
	void removeDino(const char* name);

	/**
	 * @brief 
	 * @param food 
	 * @param quantity 
	 * adds a quantity of food
	*/
	void addFood(const char* food, int quantity);

	/**
	 * @brief 
	 * @return quantity of grass
	*/
	int getGrass() const;
	/**
	 * @brief
	 * @return quantity of meat
	*/
	int getMeat() const;
	/**
	 * @brief
	 * @return quantity of fish
	*/
	int getFish() const;
	/**
	 * @brief
	 * @return size of a cell
	*/
	int getCellSizeAt(int index) const;
	/**
	 * @brief
	 * @return free space in a cell
	*/
	int getFreeSpaceAt(int index) const;
	
	/**
	 * @brief 
	 * @param index 
	 * @param cage 
	 * @return era of the dinasours in a cage 
	*/
	Era getEraAt(int index, int cage) const;
	
	/**
	 * @brief 
	 * @param index 
	 * @return climate at the cage
	*/
	Climate getClimateAt(int index) const;
	
	/**
	 * @brief 
	 * @param index1 
	 * @param index2 
	 * @return dinasour
	*/
	Dinasour getDinoAt(int index1, int index2) const;
	/**
	 * @brief 
	 * @param filename 
	 * reads information from file
	*/
	void readFromFile(const char* filename);
private:
	int foodStorage[3];

	std::vector<Cage> cages;

/**
 * @brief 
 * @param filename 
 * @param zoo 
 * saves information to file
*/
friend void saveToFile(const char* filename, const Zoo& zoo);
};

