#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include <vector>

class Unit;

class UnitManager
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