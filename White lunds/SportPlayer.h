#pragma once
#include "People.h"
class SportPlayer : public People
{
public:
	virtual void changeCapacity();
private:
	int timeForTrening;
	int intence;
};

