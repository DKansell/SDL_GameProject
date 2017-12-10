#include "Player.h"
#include <iostream>


Player::Player(int playerX, int playerY, int pNum) :
	lives(0),
	speed(2),
	score(0),
	pNum(pNum),
	isInvincible(false),
	speedBoost(false),
	//spriteRect({ SPRITE_SIZE * 2, SPRITE_SIZE * 3, SPRITE_SIZE, SPRITE_SIZE }),
	//playerRect({ SPRITE_SIZE * playerX, HUD_HEIGHT + SPRITE_SIZE * playerY, SPRITE_SIZE, SPRITE_SIZE })
	playerX(playerX),
	playerY(playerY),
	spriteX(0),
	spriteY(0)
{
	if (pNum == 1) {
		Renderer::Instance()->LoadTexture("Player1", PATH_SPRITES1);
	}
	else if (pNum == 2) {
		Renderer::Instance()->LoadTexture("Player2", PATH_SPRITES2);
	}
}


Player::~Player()
{
}

int Player::getLives() {
	return lives;
}

void Player::setLives(int nLives) {
	lives += nLives;
}

float Player::getSpeed(){
	return speed;
}

void Player::setSpeed(float newSpeed) {
	speed = newSpeed;
}

int Player::getScore() {
	return score;
}

void Player::setScore(int points) {
	score += points;
}

void Player::Draw() {
	
	if (pNum == 1) {
		Renderer::Instance()->PushSprite("Player1", { SPRITE_SIZE * spriteX, SPRITE_SIZE * spriteY, SPRITE_SIZE, SPRITE_SIZE }, { SPRITE_SIZE * playerX, HUD_HEIGHT + SPRITE_SIZE * playerY, SPRITE_SIZE, SPRITE_SIZE });
	}
	else if (pNum == 2) {
		Renderer::Instance()->PushSprite("Player2", { SPRITE_SIZE * spriteX, SPRITE_SIZE * spriteY, SPRITE_SIZE, SPRITE_SIZE }, { SPRITE_SIZE * playerX, HUD_HEIGHT + SPRITE_SIZE * playerY, SPRITE_SIZE, SPRITE_SIZE });
	}
}

void Player::Update() {

}

int Player::getX() {
	return playerX;
}

void Player::setX(int x) {
	playerX = x;
}

int Player::getY() {
	return playerY;
}

void Player::setY(int y) {
	playerY = y;
}

void Player::setSpriteX(int x) {
	spriteX = x;
}

void Player::setSpriteY(int y) {
	spriteY = y;
}

