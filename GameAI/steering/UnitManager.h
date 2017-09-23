#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include <vector>
#include "Trackable.h"

class Kinematic;
class KinematicUnit;
class GraphicsBuffer;

class UnitManager : public Trackable
{
	private :
		std::vector <KinematicUnit*> mpUnits;

	public :
		UnitManager();
		~UnitManager();

		void AddUnit(KinematicUnit* uni, int AItype);
		void RemoveUnit(KinematicUnit* uni);
		void RemoveRandomUnit();
		KinematicUnit* GetUnit(int id);

		void UnitUpdate(float t);
		void UnitDraw(GraphicsBuffer* buffer);
};

#endif