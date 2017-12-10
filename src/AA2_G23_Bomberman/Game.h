#pragma once
#include "Scene.h"
#include "Ranking.h"
#include "Menu.h"
#include "Play.h"


enum class scenes { Menu, Play, Ranking, EXIT_GAME };
class Game
{
public:
	Game();
	~Game();
	void GameLoop();
private:
	Scene *GameScene;
	scenes currentScene;
};

