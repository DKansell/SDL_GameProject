#pragma once
#include "Renderer.h"

enum class GameObjects { WALL, BLOCK, EMPTY, BOMB, EXPLOSION, PW_CASCO, PW_PATINES};
class Cell
{
public:
	Cell(int x, int y, GameObjects T, bool walkable, bool breakable);
	~Cell();
	void Draw();

	GameObjects Type;
	SDL_Rect cellRect;
	SDL_Rect spriteRect;
	bool isWalkable;
	bool isBreakable;
	int xPos;
	int yPos;
	
};

