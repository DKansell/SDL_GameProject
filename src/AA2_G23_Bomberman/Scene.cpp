#include "Scene.h"



Scene::Scene() 
{
	currentSceneState = states::Running;
	sceneBackground = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer::Instance()->LoadTexture("background", PATH_MENUBG);
} 


Scene::~Scene()
{
}
