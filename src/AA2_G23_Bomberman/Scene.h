#pragma once
#include "Types.h"
#include "Renderer.h"
#include <string.h>
#include <SDL.h>

enum class states { Running, Exit, RunLV1, RunLV2, GoTo_Ranking };
class Scene
{
public:
	SDL_Rect sceneBackground;
	states currentSceneState;

	Scene();
	~Scene();
	virtual void Update() = 0;
	virtual void EventHandle() = 0;
	virtual void Draw() = 0;

};