#include "Game.h"



Game::Game() 
{
	currentScene = scenes::Menu;
	GameScene = new Menu();
}


Game::~Game()
{
}

void Game::GameLoop()
{
	while (currentScene != scenes::EXIT_GAME)
	{
		GameScene->Draw();
		GameScene->Update();
		GameScene->EventHandle();

		switch (GameScene->currentSceneState)
		{
		case states::Running:
			break;
		case states::RunLV1:
			delete GameScene;
			GameScene = new Play(1);
			currentScene = scenes::Play;
			break;
		case states::RunLV2:
			delete GameScene;
			GameScene = new Play(2);
			currentScene = scenes::Play;
			break;
		case states::GoTo_Ranking:
			/*delete GameScene;
			GameScene = new Ranking();
			currentScene = scenes::Ranking;*/
			break;
		case states::Exit:
			/*GameScene->~Scene();
			GameScene = new Menu();
			currentScene = scenes::Menu;*/
			delete GameScene;
			currentScene = scenes::EXIT_GAME;
			break;
		default:
			break;
		}

	}
}