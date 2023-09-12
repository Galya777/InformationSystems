#include "SportPlayer.h"

void SportPlayer::changeCapacity()
{
	lunds->setHealthy(lunds->getHealthy() + timeForTrening * intence);
	lunds->setIll(lunds->getIll() + timeForTrening * intence);
}
