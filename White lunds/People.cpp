#include "People.h"
#include <iostream>

People::People(std::string name, int age, Person type)
{
    this->name = name;
    this->age = age;
    makeLunds();
    this->typ = type;
}

People::People()
{
    typ = UNKNOWN;
    name = "";
    age = 0;
    lunds->setCapacity(typ, 0);
    lunds->setHealthy(0);
    lunds->setIll(0);
    illnesses.push_back(Illness());
}

Person People::getType()
{
    return typ;
}

int People::getAge()
{
    return age;
}

std::string People::getName() const
{
    return name;
}

void People::makeLunds()
{
    lunds->setHealthy(100-illnesses.capacity());
    lunds->setIll(illnesses.capacity());
    lunds->setCapacity(typ, age);
}

void People::addIllness(Illness illness)
{
    illnesses.push_back(illness);
}

void People::heal(std::string name)
{
    bool found = false;
    for (int i = 0; i < illnesses.capacity(); ++i) {
        if (illnesses.at(i).getName() == name) {
            illnesses.erase(illnesses.begin()+i);
            found = true;
        }
    }
    if (found == false) {
        std::cout << "The patient is not ill from this!";
    }
}

void People::changeCapacity(int cig)
{
    lunds->setHealthy(lunds->getHealthy() - cig);
    lunds->setIll(lunds->getIll() + cig);
}
