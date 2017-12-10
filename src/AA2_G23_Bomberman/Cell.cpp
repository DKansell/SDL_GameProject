#include "Cell.h"




Cell::Cell(int x, int y, GameObjects T, bool walkable, bool breakable, int ownerID, GameObjects L) :
	Type(T),
	lastCellType(L),
	xPos(x),
	yPos(y),
	isWalkable(walkable),
	isBreakable(breakable),
	ownerID(ownerID)
{
	switch (Type)
	{
	case GameObjects::WALL:
		spriteRect = {0, 0, SPRITE_SIZE, SPRITE_SIZE};
		break;
	case GameObjects::BLOCK:
		spriteRect = { SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE};
		break;
	case GameObjects::EMPTY:
		break;
	case GameObjects::BOMB:
		spriteRect = { 0, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE };
		bombTime = clock();
		break;
	case GameObjects::EXPLOSION:
		spriteRect = { 0, 0, SPRITE_SIZE, SPRITE_SIZE };
		explosionTime = clock();
		break;
	case GameObjects::PW_CASCO:
		spriteRect = { 2 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE };
		break;
	case GameObjects::PW_PATINES:
		spriteRect = { SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE };
		break;
	default:
		break;
	}
}

Cell::~Cell()
{
}

void Cell::Draw(){
	if (Type == GameObjects::EXPLOSION) {
		Renderer::Instance()->PushSprite("explosion", spriteRect, { SPRITE_SIZE * xPos, HUD_HEIGHT + SPRITE_SIZE * yPos, SPRITE_SIZE, SPRITE_SIZE });
	}
	else if (Type == GameObjects::EMPTY) {
		//do nothing
	}
	else {
		Renderer::Instance()->PushSprite("items", spriteRect, { SPRITE_SIZE * xPos, HUD_HEIGHT + SPRITE_SIZE * yPos, SPRITE_SIZE, SPRITE_SIZE });
	}
}

bool Cell::BombManager() {
	clock_t deltaTime = TIME_TO_EXPLODE * CLOCKS_PER_SEC;
	if (abs(bombTime - clock()) >= deltaTime) {
		return true;
	}
	else {
		return false;
	}
}

bool Cell::ExplosionManager() {
	clock_t deltaTime = EXPLOSION_DURATION * CLOCKS_PER_SEC;
	if (abs(explosionTime - clock()) >= deltaTime) {
		return true;
	}
	else {
		return false;
	}
}

void Cell::setOwnerID(int id) {
	ownerID = id;
}

int Cell::getOwnerID() {
	return ownerID;
}

GameObjects Cell::SpawnPowerup() {
	int aux = rand() % 10;
	if (aux == 1) return GameObjects::PW_CASCO;
	else if (aux == 2) return GameObjects::PW_PATINES;
	else return GameObjects::EMPTY;
}