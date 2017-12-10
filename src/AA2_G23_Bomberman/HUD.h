#pragma once
#include "Renderer.h"
#include "Player.h"

class HUD
{
public:
	HUD(Player &player1, Player &player2);
	~HUD();

	void Draw();
private:
	Player* player1;
	Player* player2;
	SDL_Rect HUDRect;
	SDL_Rect player1Rect;
	SDL_Rect player2Rect;
	SDL_Rect scoreRect;
	SDL_Rect livesRect;
	
};

