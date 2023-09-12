#pragma once
#pragma warning(disable:4996)
#include <cstring>
#include <fstream>
enum Rank {
		YOUNGLING = -1,
		INITIATE=0,
		PADAWAN=1,
		KNIGHT_ASPIRANT=2,
		KNIGHT=3,
		MASTER=4,
		BATTLE_MASTER=5,
		GRAND_MASTER =6
	};
class Jedi
{
	
public:
	Jedi(const char* name, int rank, int age, const char* color, double power);
	Jedi();
	Jedi(const Jedi& other);
	Jedi operator=(const Jedi& other);
	~Jedi();

	void setName(const char* name);
	void setRank(int rank);
	void setAge(int age);
	void setColor(const char* color);
	void setPower(double power);
	
	void printRank();

	void printJedi();

	char* getName()const;
	Rank getRank()const;
	int getAge()const;
	char* getColor()const;
	double getPower()const;

	friend std::ostream& operator<<(std::ostream& out, const Jedi& other);
	virtual void writeToFile(std::fstream& file) const;

private:
	void initialize(const char* name, int rank, int age, const char* color, double power);
	void copy(const Jedi& other);
	void clear();
	

	char* name;
	Rank rank;
	int age;
	char* color;
	double power;
};

