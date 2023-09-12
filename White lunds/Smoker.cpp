#include "Smoker.h"

Smoker::Smoker(int cigarettes)
{
	this->cigarettes = cigarettes;
}

Smoker::Smoker()
{
	Person();
	cigarettes = 0;
}

void Smoker::changeCapacity(int cig)
{
	lunds->setHealthy(lunds->getHealthy() - cig);
	lunds->setIll(lunds->getIll() + cig);

}
