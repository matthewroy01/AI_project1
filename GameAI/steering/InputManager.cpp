#include "InputManager.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "GameMessageManager.h"
#include "PlayerMoveToMessage.h"
#include "UnitCreateArriveMessage.h"
#include "UnitCreateSeekMessage.h"
#include "UnitDeleteRandomMessage.h"
#include "Game.h"
#include "GraphicsSystem.h"
#include "Vector2D.h"
#include <sstream>
#include <stdio.h>

InputManager::InputManager()
{
	mAdown = false;
	mSdown = false;
	mDdown = false;
}

InputManager::~InputManager()
{

}

void InputManager::Update()
{
	//get input - should be moved someplace better
	ALLEGRO_MOUSE_STATE mouseState;
	al_get_mouse_state(&mouseState);

	if (al_mouse_button_down(&mouseState, 1))//left mouse click
	{
		Vector2D pos(mouseState.x, mouseState.y);
		GameMessage* pMessage = new PlayerMoveToMessage(pos);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	//create mouse text
	std::stringstream mousePos;
	mousePos << mouseState.x << ":" << mouseState.y;

	//write text at mouse position
	al_draw_text(GET_GAME->getFont(), al_map_rgb(255, 255, 255), mouseState.x, mouseState.y, ALLEGRO_ALIGN_CENTRE, mousePos.str().c_str());

	GRAPHICS_SYSTEM->swap();

	//get current keyboard state
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

	//if 'escape' key was down then exit the loop
	if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
	{
		GET_GAME->setShouldExit(true);
	}

	//if 'a' key is pressed create a random unit that arrives to the player's position
	if (al_key_down(&keyState, ALLEGRO_KEY_A) && !mAdown)
	{
		mAdown = true;
		GameMessage* pMessage = new UnitCreateArriveMessage();
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	//if 's' key is pressed create a random unit that seeks to the player's position
	if (al_key_down(&keyState, ALLEGRO_KEY_S) && !mSdown)
	{
		mSdown = true;
		GameMessage* pMessage = new UnitCreateSeekMessage();
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	//if 's' key is pressed delete a random unit
	if (al_key_down(&keyState, ALLEGRO_KEY_D) && !mDdown)
	{
		mDdown = true;
		GameMessage* pMessage = new UnitDeleteRandomMessage();
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	// check to see if you're still pressing the button so you can't create or delete a unit by just holding the key
	if (!al_key_down(&keyState, ALLEGRO_KEY_A)) { mAdown = false; }
	if (!al_key_down(&keyState, ALLEGRO_KEY_S)) { mSdown = false; }
	if (!al_key_down(&keyState, ALLEGRO_KEY_D)) { mDdown = false; }
}