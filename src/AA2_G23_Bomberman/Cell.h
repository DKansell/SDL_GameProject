#pragma once
#include "Renderer.h"
#include <ctime>
#include <stdio.h>      
#include <stdlib.h> 

enum class GameObjects { WALL, BLOCK, EMPTY, BOMB, EXPLOSION, PW_CASCO, PW_PATINES};
class Cell
{
public:
	Cell(int x, int y, GameObjects T, bool walkable, bool breakable, int ownerID, GameObjects L);
	~Cell();

	void Draw();
	bool BombManager();
	bool ExplosionManager();
	void setOwnerID(int id);
	int getOwnerID();
	GameObjects SpawnPowerup();

	GameObjects Type;
	GameObjects lastCellType;
	SDL_Rect cellRect;
	SDL_Rect spriteRect;
	bool isWalkable;
	bool isBreakable;
	int xPos;
	int yPos;
	
private:
	int ownerID;
	clock_t bombTime;
	clock_t explosionTime;
};

