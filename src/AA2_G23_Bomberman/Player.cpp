#include "Player.h"
#include <iostream>


Player::Player(int playerX, int playerY, int pNum) :
	lives(0),
	speed(2),
	score(0),
	pNum(pNum),
	isInvincible(false),
	speedBoost(false),
	canDropBomb(true),
	playerX(playerX),
	playerY(playerY),
	spriteX(0),
	spriteY(0)
{
	//Carga de sprites segun Player 1 o Player 2
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

bool Player::getCanDropBomb() {
	return canDropBomb;
}

void Player::setCanDropBomb(bool b) {
	canDropBomb = b;
}

void Player::setCasco(bool b) {
	isInvincible = b;
}

bool Player::getCasco() {
	return isInvincible;
}

void Player::setPatines(bool b) {
	speedBoost = b;
}

bool Player::getPatines() {
	return speedBoost;
}