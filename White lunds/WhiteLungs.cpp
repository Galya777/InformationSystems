#include <iostream>
#include <vector>
#include <string>
#include "People.h"
#include "Smoker.h"
void addPerson(std::vector<People> patients) {
    std::string name;
    std::string type;
    int age;
    Person per;
           std::cout << "Enter name!";
            std::cin >> name;
            std::cout << "Enter the age!";
            std::cin >> age;
            std::cout << "Enter the type of person!";
            std::cin >> type;
            if (type == "smoker") {
                per = SMOKER;
            }else if (type == "sporter") {
                per = SPORTPLAYER;
            } else {
                per = UNKNOWN;
            }
            People person(name,age,per); 
            patients.push_back(person);
}
void addIllness(std::vector<Illness>illnesses) {
    std::string name;
     std::string type;
           int stadium;
           std::cout << "Enter type!";
           std::cin >> type;
           std::cout << "Enter name!";
           std::cin >> name;
           std::cout << "Enter stadium (between 1 and 4): ";
           std::cin >> stadium;
          Illness illness(type,name,stadium);
          illnesses.push_back(illness);
}
bool findPerson(std::vector<People> patients,std::string name){
    for (int i = 0; i < patients.capacity(); ++i) {
        if (patients.at(i).getName() == name) {
            patients.erase(patients.begin() + i);
            return true;
        }
    }
    return false;
}
bool findIllness(std::vector<Illness> illnesses, std::string name) {
    for (int i = 0; i < illnesses.capacity(); ++i) {
        if (illnesses.at(i).getName() == name) {
            illnesses.erase(illnesses.begin() + i);
            return true;
        }
    }
    return false;
} int returnPerson(std::vector<People> patients, std::string name) {
    for (int i = 0; i < patients.capacity(); ++i) {
        if (patients.at(i).getName() == name) {
            return i;
        }
    }
    return 0;
}
Illness returnIllness(std::vector<Illness> illnesses, std::string name) {
    for (int i = 0; i < illnesses.capacity(); ++i) {
        if (illnesses.at(i).getName() == name) {
            return illnesses.at(i);
        }
    }
    return Illness();
}
int main()
{
    std::vector<People> patients;
    std::vector<Illness> illnesses;  
    std::string command;
    std::string name;
    do {
        std::cout << "Enter your command: ";
        std::cin >> command;
        if (command == "patient") {
            addPerson(patients);
        }
        else if (command == "illness") {           
            addIllness(illnesses);
        }
        else if (command == "make ill") {
            std::cout << "Enter the name of the person: ";
            std::cin >> name;
            if (findPerson(patients, name) == true) {
                std::cout << "Enter the illness: ";
                std::cin >> name;
                if (findIllness(illnesses, name) == true) {
                    patients.at(returnPerson(patients, name)).addIllness(returnIllness(illnesses, name));
                    std::cout << "The illness is added!";
                }else {
                    std::cout << "The illness is not it the system. You have to add it first.";
                }
            }
            else {
                std::cout << "Sorry, this person is not registrated!";
            }
        }
        else if (command == "do something") {
            std::cout << "Enter the name of the person: ";
            std::cin >> name;
            if (findPerson(patients, name) == true) {
                if (patients.at(returnPerson(patients, name)).getType() == SMOKER) {
                    std::cout << "Enter the number of cigarettes: ";
                    int cig;
                    std::cin >> cig;
                   patients.at(returnPerson(patients, name)).changeCapacity(cig);
                } else  if (patients.at(returnPerson(patients, name)).getType() == SPORTPLAYER) {
                    std::cout << "Enter the hours of trening: ";
                    int hours;
                    std::cin >> hours;
                    patients.at(returnPerson(patients, name)).changeCapacity(hours);
                }
                else {
                    std::cout << "You can not do anything!";
                }
            }
            else {
                std::cout << "Sorry, this person is not registrated!";
            }
        }
        else if (command == "heal") {
            std::cout << "Enter the name of the person: ";
            std::cin >> name;
            if (findPerson(patients, name) == true) {
                std::cout << "Enter the name of the illness: ";
                std::string illname;
                std::cin >> illname;
                patients.at(returnPerson(patients, name)).heal(illname);
            }
            else {
                std::cout << "Sorry, this person is not registrated!";
            }
        }
    } while (command != "exit");

    return 0;
}
