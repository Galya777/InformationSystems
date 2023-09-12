#pragma once
#include "Dinasour.h"
#include <fstream>
/**
 * @class EatingMeet
 * child of Dinasour
 * describing dinasours eating meat
*/
class EatingMeet:public Dinasour
{
public:

    /**
     * @brief constructor
     * @param name
     * @param sex
     * @param category
    */
    EatingMeet(std::string name, std::string sex, std::string category);

    /**
     * @brief type
     * @return type of the dinasour
    */
    Type type() const { return Type::CARNIVOROUS; };

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
    Food get_feed() const { return Food::MEAT; }

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
    Dinasour* clone() const { return new EatingMeet(*this); };

    /**
     * @brief
     * @param filename
     * prints information in a file
    */
    void print(const char* filename);

};

