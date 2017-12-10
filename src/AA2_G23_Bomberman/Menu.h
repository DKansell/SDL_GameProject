#include "Scene.h"
#include "Renderer.h"
#include <SDL.h>
#include <iostream>


#pragma once

class Menu : public Scene
{
private:
	Rect bgRect;
	Rect cursorRect;
	Rect cursorTarget;

	SDL_Rect buttonLv1Rect;
	SDL_Rect buttonLv2Rect;
	SDL_Rect rankingRect;
	SDL_Rect exitRect;
	SDL_Rect soundRect;
public:
	Menu();
	~Menu();

	void Draw() override;
	void Update() override;
	void EventHandle() override;
};