#include "Scene.h"
#include "Renderer.h"
#include "Player.h"
#include "Cell.h"
#include <vector>

#pragma once

class Play : public Scene
{
public:
	Play(int map);
	~Play();

	void Draw() override;
	void Update() override;
	void EventHandle() override;
	void EditMap(int x, int y, GameObjects T, bool walkable, bool breakable);

private:
	SDL_Rect bgRect;
	Player player1;
	Player player2;
	std::string configPath;
	std::vector<std::vector<Cell*>> gameMap; //Matriz de juego
	int playTime;
	int numRows;
	int numColumns;
	int gameDuration;
};