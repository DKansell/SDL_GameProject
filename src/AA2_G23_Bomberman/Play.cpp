#include "Play.h"
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <sstream>
#include <string.h>
#include <iostream>




Play::Play(int map) :
	Scene::Scene(),
	player1(1, 1, 1),
	player2(13, 11, 2),
	bgRect({0,0,SCREEN_WIDTH, SCREEN_HEIGHT})
{
	if (map == 1) configPath = "../../res/files/config1.xml";
	else if (map == 2) configPath = "../../res/files/config2.xml";

	rapidxml::xml_document<> doc;
	std::ifstream file(configPath);
	std::stringstream buffer;

	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<> *pRoot = doc.first_node();
	
	numRows = std::stoi(pRoot->first_attribute("numRows")->value());
	numColumns = std::stoi(pRoot->first_attribute("numColumns")->value());
	player1.setLives(std::stoi(pRoot->first_attribute("playerLives")->value()));
	player2.setLives(std::stoi(pRoot->first_attribute("playerLives")->value()));
	gameDuration = std::stoi(pRoot->first_attribute("gameDuration")->value());

	//Creación del Mapa
	
	/*gameMap.resize(numRows);
	for (int i = 0; i < numRows; ++i)
		gameMap[i].resize(numColumns);*/

	int i = 0;
	gameMap = std::vector<std::vector<Cell*>>(numRows, std::vector<Cell*>(numColumns));
	
	for (rapidxml::xml_node<> *pNode = pRoot->first_node("Row0"); pNode; pNode = pNode->next_sibling()) {
		int j = 0;
		for (rapidxml::xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
			if (std::string(pNodeI->value()) == "0") {
				gameMap[i][j] = new Cell(j, i, GameObjects::WALL, false, false, 0, GameObjects::EMPTY);
			}
			else if (std::string(pNodeI->value()) == "1") {
				gameMap[i][j] = new Cell(j, i, GameObjects::BLOCK, false, true, 0, GameObjects::EMPTY);
			}
			else {
				gameMap[i][j] = new Cell(j, i, GameObjects::EMPTY, true, false, 0, GameObjects::EMPTY);
			}
			j++;
		}
		i++;
	}

	Renderer::Instance()->LoadTexture("background", PATH_MENUBG);
	Renderer::Instance()->LoadTexture("items", PATH_ITEMS);
	Renderer::Instance()->LoadTexture("explosion", PATH_EXPLOSION);
};


Play::~Play()
{
}

void Play::Draw() {
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage("background", bgRect);
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			gameMap[i][j]->Draw();
		}
	}
		player1.Draw();
		player2.Draw();
		Renderer::Instance()->Render();
}

void Play::Update() {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			//Update de las Bombas
			if (gameMap[i][j]->Type == GameObjects::BOMB) {
				if (gameMap[i][j]->BombManager()) {
					//Crear explosion
					if (gameMap[i][j]->getOwnerID() == 1) {
						player1.setCanDropBomb(true);
						GameObjects lastType;
						//RADIO EXPLOSION
						bool hitWallUp = false;
						bool hitWallDown = false;
						int expRadius = 0;
						while (expRadius < 3) {
							if (!hitWallDown) {
								if (gameMap[i + expRadius][j]->Type != GameObjects::WALL) {
									lastType = gameMap[i + expRadius][j]->Type;
									gameMap[i + expRadius][j] = new Cell(j, i + expRadius, GameObjects::EXPLOSION, true, false, 1, lastType);
								}
								else {
									hitWallDown = true;
								}
							}
							else if (!hitWallUp) {
								if (gameMap[i - expRadius][j]->Type != GameObjects::WALL) {
									lastType = gameMap[i - expRadius][j]->Type;
									gameMap[i - expRadius][j] = new Cell(j, i - expRadius, GameObjects::EXPLOSION, true, false, 1, lastType);
								}
								else {
									hitWallUp = true;
								}
							}
							expRadius++;
						}
						bool hitWallRight = false;
						bool hitWallLeft = false;
						expRadius = 0;
						while (expRadius < 3) {
							if(!hitWallRight){
								if (gameMap[i][j + expRadius]->Type != GameObjects::WALL) {
									lastType = gameMap[i][j + expRadius]->Type;
									gameMap[i][j + expRadius] = new Cell(j + expRadius, i, GameObjects::EXPLOSION, true, false, 1, lastType);
								}
								else {
									hitWallRight = true;
								}
							}
							else if (!hitWallLeft) {
								if (gameMap[i][j - expRadius]->Type != GameObjects::WALL) {
									lastType = gameMap[i][j - expRadius]->Type;
									gameMap[i][j - expRadius] = new Cell(j + expRadius, i, GameObjects::EXPLOSION, true, false, 1, lastType);
								}
								else {
									hitWallLeft = true;
								}
							}
							expRadius++;
						}
					}
					else if (gameMap[i][j]->getOwnerID() == 2) {
						player2.setCanDropBomb(true);
						gameMap[i][j] = new Cell(j, i, GameObjects::EXPLOSION, true, false, 2, GameObjects::BOMB);
						//RADIO EXPLOSION
					}
				}
			}
			if (gameMap[i][j]->Type == GameObjects::EXPLOSION) {
				if (gameMap[i][j]->ExplosionManager()) {
					//Comprobar colisiones
					//Sumar Puntos
					//Limpiar sprites de las explosiones
					gameMap[i][j] = new Cell(j, i, GameObjects::EMPTY, true, false, 2, GameObjects::EXPLOSION);
					
				}
			}
		}
	}
	player1.Update();
	player2.Update();
}

void Play::EventHandle() {

	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_UP) {
				player2.setSpriteX(0);
				player2.setSpriteY(0);
				if (gameMap[player2.getY() - 1][player2.getX()]->isWalkable) player2.setY(player2.getY() - 1);
			}
			if (event.key.keysym.sym == SDLK_DOWN) {
				player2.setSpriteX(0);
				player2.setSpriteY(2);
				if (gameMap[player2.getY() + 1][player2.getX()]->isWalkable) player2.setY(player2.getY() + 1);
			}
			if (event.key.keysym.sym == SDLK_LEFT) {
				player2.setSpriteX(0);
				player2.setSpriteY(1);
				if (gameMap[player2.getY()][player2.getX()-1]->isWalkable) player2.setX(player2.getX() - 1);
			}
			if (event.key.keysym.sym == SDLK_RIGHT) {
				player2.setSpriteX(0);
				player2.setSpriteY(3);
				if (gameMap[player2.getY()][player2.getX() + 1]->isWalkable) player2.setX(player2.getX() + 1);
			}
			if (event.key.keysym.sym == SDLK_w) {
				player1.setSpriteX(0);
				player1.setSpriteY(0);
				if (gameMap[player1.getY() - 1][player1.getX()]->isWalkable) player1.setY(player1.getY() - 1);
			}
			if (event.key.keysym.sym == SDLK_s) {
				player1.setSpriteX(0);
				player1.setSpriteY(2);
				if (gameMap[player1.getY() + 1][player1.getX()]->isWalkable) player1.setY(player1.getY() + 1);
			}
			if (event.key.keysym.sym == SDLK_a) {
				player1.setSpriteX(0);
				player1.setSpriteY(1);
				if (gameMap[player1.getY()][player1.getX() - 1]->isWalkable) player1.setX(player1.getX() - 1);
			}
			if (event.key.keysym.sym == SDLK_d) {
				player1.setSpriteX(0);
				player1.setSpriteY(3);
				if (gameMap[player1.getY()][player1.getX() + 1]->isWalkable) player1.setX(player1.getX() + 1);
			}
			if (event.key.keysym.sym == SDLK_SPACE) {
				if (player1.getCanDropBomb()) {
					gameMap[player1.getY()][player1.getX()] = new Cell(player1.getX(), player1.getY(), GameObjects::BOMB, true, false, 1, GameObjects::EMPTY);
					player1.setCanDropBomb(false);
				}
			}
			if (event.key.keysym.sym == SDLK_RCTRL) {
				if (player2.getCanDropBomb()) {
					gameMap[player2.getY()][player2.getX()] = new Cell(player2.getX(), player2.getY(), GameObjects::BOMB, true, false, 2, GameObjects::EMPTY);
					player2.setCanDropBomb(false);
				}
			}
			break;

		default:;
		}
	}
}

