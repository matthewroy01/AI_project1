#include "UnitManager.h"

#include "KinematicUnit.h"

UnitManager::UnitManager()
{

}

UnitManager::~UnitManager()
{

}

void UnitManager::AddUnit(Unit* uni)
{
	// when user hits the 'A' key, add a unit exactly 200 pixels away from the player's location
	// this new unit tries to ARRIVE at the player's current location

	// when user hits the 'S' key, add a unit exactly 200 pixels away from the player's location
	// this new unit tries to SEEK at the player's current location
}

void UnitManager::RemoveUnit(Unit* uni)
{
	// when user hits the 'D' key, delete a random unit (not the player)
	// when all units (besides the player) are deleted, exit the game
}