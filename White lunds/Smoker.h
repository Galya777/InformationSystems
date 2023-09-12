#pragma once
#include "People.h"
class Smoker: public People
{
public:
	Smoker(int cigarettes);
	Smoker();
	virtual void changeCapacity(int cig);
private:
	int cigarettes;
};

