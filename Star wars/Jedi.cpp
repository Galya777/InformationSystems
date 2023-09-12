#include "Jedi.h"
#include <iostream>

char* Jedi::getName() const
{
    return name;
}

Rank Jedi::getRank() const
{
    return rank;
}

int Jedi::getAge() const
{
    return age;
}

char* Jedi::getColor() const
{
    return color;
}

double Jedi::getPower() const
{
    return power;
}

void Jedi::writeToFile(std::fstream& file) const
{
    file<< name << " " << rank << " " << age << " " << color << " " << power;
}

void Jedi::initialize(const char* name, int rank, int age, const char* color, double power)
{
    setName(name);
    setRank(rank);
    setAge(age);
    setColor(color);
    setPower(power);

}

void Jedi::copy(const Jedi& other)
{
    initialize(other.name, other.rank, other.age, other.color, other.power);
}

void Jedi::clear()
{
    delete[] name;
    delete[] color;
}

Jedi::Jedi(const char* name, int rank, int age, const char* color, double power)
{
    initialize( name, rank, age, color, power);
}

Jedi::Jedi()
{
    initialize("", -1, 0, "", 0.0);
}

Jedi::Jedi(const Jedi& other)
{
    copy(other);
}

Jedi Jedi::operator=(const Jedi& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

Jedi::~Jedi()
{
    clear();
}

void Jedi::setName(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Jedi::setRank(int rank)
{
    switch (rank)
    {
    case -1:
        this->rank = YOUNGLING;
        break;
    case 0:
        this->rank = INITIATE;
        break;
    case 1:
        this->rank = PADAWAN;
        break;
    case 2:
        this->rank = KNIGHT_ASPIRANT;
        break;
    case 3:
        this->rank = KNIGHT;
        break;
    case 4:
        this->rank = MASTER;
        break;
    case 5:
        this->rank = BATTLE_MASTER;
        break;
    case 6:
        this->rank = GRAND_MASTER;
        break;
    default:
        std::cout << "This jedi is the lowest or the highest rank!"<<std::endl;
        break;
    }
}

void Jedi::setAge(int age)
{
    this->age = age;
}

void Jedi::setColor(const char* color)
{
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
}

void Jedi::setPower(double power)
{
    this->power = power;
}



void Jedi::printRank()
{
    switch (this->rank)
    {
    case YOUNGLING:
        std::cout << "YOUNGLING";
        break;
    case INITIATE:
        std::cout << "INITIATE";
        break;
    case PADAWAN:
        std::cout << "PADAWAN";
        break;
    case KNIGHT_ASPIRANT:
        std::cout << "KNIGHT_ASPIRANT";
        break;
    case KNIGHT:
        std::cout << "KNIGHT";
        break;
    case MASTER:
        std::cout << "MASTER";
        break;
    case BATTLE_MASTER:
        std::cout << "BATTLE_MASTER";
        break;
    case GRAND_MASTER:
        std::cout << "GRAND_MASTER";
        break;
    default:
        std::cout << "YOUNGLING";
    }
}

void Jedi::printJedi()
{
    std::cout << name << " "; printRank();
    std::cout << " " << age << " " << color << " " << power<<std::endl;
}



std::ostream& operator<<(std::ostream& out, const Jedi& other)
{
    out << other.name << " " << other.rank << " " << other.age << " " << other.color << " " << other.power;
    return out;
}
