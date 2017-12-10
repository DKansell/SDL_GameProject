#pragma once
#include "Renderer.h"
#include "Types.h"

class Player
{
private:
	int lives;
	int score;
	int playerX;
	int playerY;
	int spriteX;
	int spriteY;
	float speed;
	bool isInvincible;
	bool speedBoost;
	int pNum;
	SDL_Rect spriteRect;
	SDL_Rect playerRect;

public:
	Player(int x, int y, int pNum);
	~Player();

	int getLives();
	void setLives(int nLives);
	float getSpeed();
	void setSpeed(float spd);
	int getScore();
	void setScore(int points);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void setSpriteX(int x);
	void setSpriteY(int y);

	void Draw();
	void Update();

};

