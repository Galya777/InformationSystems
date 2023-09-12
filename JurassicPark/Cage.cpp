#include "Cage.h"

Climate Cage::getClimate() const
{
    return climat;
}

Era Cage::getEraAt(int index) const
{
    return eras.at(index);
}

int Cage::getSize() const
{
    return size;
}

int Cage::getFreeSpace() const
{
    return spaceLeft;
}

Dinasour Cage::getDinoAt(int index) const
{
    return dinos.at(index);
}

Cage::Cage(int size, Climate climat)
{
    this->size = size; 
    this->climat = climat;
    spaceLeft = size;
    dinos.push_back(Dinasour());
    eras.push_back(Era());
}

Cage::Cage()
{
    this->size = 0;
    spaceLeft = size;
    dinos.push_back(Dinasour());
    eras.push_back(Era());
}

Cage::Cage(const Cage& other)
{
    this->size = other.size;
    this->climat = other.climat;
    spaceLeft = size;
    dinos=other.dinos;
    eras = other.eras;
}

void Cage::addDino(Dinasour dino, Era era)
{
    if (spaceLeft>0) {
        dinos.push_back(dino);
        eras.push_back(era);
    }
    else {
        std::cout << "Not enough space in this cage!";
    }
    --spaceLeft;
}

void Cage::removeDino(std::string name)
{
    for (int i = 0; i < dinos.size(); ++i) {
        if (dinos.at(i).getName() == name) {
            dinos.erase(dinos.begin() + i);
            eras.erase(eras.begin() + i);
        }
    }
}
