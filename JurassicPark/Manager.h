#pragma once
#include "Zoo.h"
using namespace std;
/**
 * @brief 
 * this calss allows the user to control the zoo 
*/
class Manager
{
public:
	/**
	 * @brief 
	 * reads the zoo from file
	*/
	Manager();

	/**
	 * @brief 
	 * the main menu
	*/
	void menu();
private:
	Zoo zoo;
	/**
	 * @brief 
	 * adds a dino
	*/
	void addDino();
	/**
	 * @brief 
	 * adds a cage 
	*/
	void addCell();
	/**
	 * @brief 
	 * removes a dino 
	*/
	void removeDino();
	/**
	 * @brief 
	 * this is where the food is stored
	*/
	void store();
	/**
	 * @brief 
	 * saves to a file
	*/
	void save();
};

