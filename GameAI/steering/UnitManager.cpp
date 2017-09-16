#include "UnitManager.h"

#include "KinematicUnit.h"

UnitManager::UnitManager()
{

}

UnitManager::~UnitManager()
{

}

void UnitManager::AddUnit(KinematicUnit* uni, int AItype)
{
	// add the new unit
	mpUnits.push_back(uni);

	switch (AItype)
	{
		case 0:
		{
			// do nothing! this is the player
			break;
		}
		case 1:
		{
			// dynamic arrive
			mpUnits[mpUnits.size() - 1]->dynamicArrive(GetUnit(0));
			break;
		}
		case 2:
		{
			// dynamic seek
			mpUnits[mpUnits.size() - 1]->dynamicSeek(GetUnit(0));
			break;
		}
	}
	// when user hits the 'A' key, add a unit exactly 200 pixels away from the player's location
	// this new unit tries to ARRIVE at the player's current location


	// when user hits the 'S' key, add a unit exactly 200 pixels away from the player's location
	// this new unit tries to SEEK at the player's current location
}

void UnitManager::RemoveUnit(KinematicUnit* uni)
{
	// when user hits the 'D' key, delete a random unit (not the player)
	// when all units (besides the player) are deleted, exit the game
}

KinematicUnit* UnitManager::GetUnit(int id)
{
	return mpUnits[id];
}

void UnitManager::UnitDraw(GraphicsBuffer* buffer)
{
	for (unsigned int i = 0; i < mpUnits.size(); i++)
	{
		mpUnits[i]->draw(buffer);
	}
}

void UnitManager::UnitUpdate(float t)
{
	for (unsigned int i = 0; i < mpUnits.size(); i++)
	{
		mpUnits[i]->update(t);
	}
}