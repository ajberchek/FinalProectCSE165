#include "Mole.h"
#include "Player.h"
#include "CollideableContainer.h"
#include "commonVariable.h"
#include <stdlib.h>

class MoleLogic
{
	public:
		MoleLogic(Player * p);
		void updateMoles(CollideableContainer * col);
		void randSelectState(Mole ** mole);
		Player * playa;
		double changeBias, coeffRand, coeffDist;
		double moleStillTimeInMillis;
};

