#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include <vector>
#include "Trackable.h"

class Unit;

class UnitManager : public Trackable
{
	private :
		std::vector <Unit*> mpUnits;

	public :
		UnitManager();
		~UnitManager();

		void AddUnit(Unit* uni);
		void RemoveUnit(Unit* uni);
};

#endif