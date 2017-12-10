#include "Cell.h"



Cell::Cell(int x, int y, GameObjects T, bool walkable, bool breakable) :
	Type (T),
	//cellRect ({ x, y, SPRITE_SIZE , SPRITE_SIZE}),
	xPos(x),
	yPos(y),
	isWalkable (walkable),
    isBreakable (breakable)
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
		break;
	case GameObjects::EXPLOSION:
		break;
	case GameObjects::PW_CASCO:
		spriteRect = { 3* SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE };
		break;
	case GameObjects::PW_PATINES:
		spriteRect = { 2 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE };
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
		//Renderer::Instance()->PushSprite("explosion", spriteRect, cellRect);
		Renderer::Instance()->PushSprite("explosion", spriteRect, { SPRITE_SIZE * xPos, HUD_HEIGHT + SPRITE_SIZE * yPos, SPRITE_SIZE, SPRITE_SIZE });
	}
	else if (Type == GameObjects::EMPTY) {
		//do nothing
	}
	else {
		//Renderer::Instance()->PushSprite("items", spriteRect, cellRect);
		Renderer::Instance()->PushSprite("items", spriteRect, { SPRITE_SIZE * xPos, HUD_HEIGHT + SPRITE_SIZE * yPos, SPRITE_SIZE, SPRITE_SIZE });
	}
}
