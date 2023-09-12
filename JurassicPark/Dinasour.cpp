#include "Dinasour.h"

bool Dinasour::validGender(std::string gender)
{
    if (gender=="male" || gender=="female") {
        return true;
    }
    return false;
}

Dinasour::Dinasour(std::string name, std::string gender, Type type)
{
    setName(name);
    setGender(gender);
    setType(type);
}

Dinasour::Dinasour()
{
    setName("");
    setGender("");
    setType(Type::WATER);
}

void Dinasour::setName(std::string name)
{
    this->name = name;
}

void Dinasour::setGender(std::string sex)
{
    if (validGender(sex) == true) {
        this->gender = sex;
    }
    else {
        std::cout << "Invalid gender!";
    }
}

void Dinasour::setType(Type type)
{
    this->type = type;
}

std::string Dinasour::getName() const
{
    return name;
}

std::string Dinasour::getGender() const
{
    return gender;
}

std::string Dinasour::getTypeToText(Type t) const
{
    std::string type;
    if (t == Type::WATER) {
        type = "water";
    } else if (t == Type::FLYING) {
        type = "flying";
    } else if (t == Type::CARNIVOROUS) {
        type = "carnivorous";
    } else if (t == Type::HEBRIVOROUS) {
        type = "hebrivous";
    }
    return type;
}

Type Dinasour::getType() const
{
    return type;
}

Era Dinasour::getEra() const
{
    Era era;
    if (type == Type::WATER) {
        era = Era::KREDA;
    } else if (type == Type::FLYING || type == Type::CARNIVOROUS) {
        era = Era::TRIAS;
    } else if (type == Type::HEBRIVOROUS) {
        era = Era::URA;
    }
    return era;
}

Type Dinasour::getTypeFromText(std::string cat) const
{
    Type t=Type::HEBRIVOROUS;
    if (cat == "water") {
        t = Type::WATER;
    } else if (cat == "flying") {
        t = Type::FLYING;
    } else if (cat == "carnivorous") {
        t = Type::CARNIVOROUS;
    } else {
        t = Type::HEBRIVOROUS;
    }
    return t;
}

void Dinasour::read(std::istream& file)
{
    std::string t = getTypeToText(type).c_str();
    file >> name >> gender >> t;
}

void Dinasour::write(std::ostream& file)
{
    file << name << " " << gender << " " << " " << type;
}


