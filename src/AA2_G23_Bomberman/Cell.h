#pragma once
#include "Renderer.h"
#include <ctime>
#include <stdio.h>      
#include <stdlib.h> 
#include <iostream>

enum class GameObjects { WALL, BLOCK, EMPTY, BOMB, EXPLOSION, PW_CASCO, PW_PATINES};
class Cell
{
public:
	Cell(int x, int y, GameObjects T, bool walkable, bool breakable, int ownerID, GameObjects L);
	~Cell();

	void Draw();
	bool BombManager(); //Controla el tiempo de vida de las bombas
	bool ExplosionManager(); //Controla el tiempo de vida de las explosiones
	void setOwnerID(int id); //Asigna una id al tile según que jugador lo genera
	int getOwnerID();
	GameObjects SpawnPowerup(); //Determina si spawnear un power up

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

