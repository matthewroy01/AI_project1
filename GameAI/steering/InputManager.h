#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Trackable.h"

class Game;

class InputManager : public Trackable
{
	private :
		bool mAdown, mSdown, mDdown;

	public :
		InputManager();
		~InputManager();

		void Update();
};

#endif