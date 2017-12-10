#include "Menu.h"



Menu::Menu() :
	Scene::Scene()
{
	//Carga font del Menú
	Font menuFont; 
	menuFont.id = SAIYAN_80;
	menuFont.path = PATH_MENUFONT;
	menuFont.size = 80;
	Renderer::Instance()->LoadFont(menuFont);


	//Texto y Opciones del Menú
	//Jugar Nivel 1
	Text buttonLevel1({ MENU_BUTTON_LVL1, "Play Level A", Color{76,0,153,0}});
	Renderer::Instance()->LoadTextureText(menuFont.id, buttonLevel1);
	Vector2 coords = Renderer::Instance()->GetTextureSize(buttonLevel1.id);
	buttonLevel1.w = coords.x;
	buttonLevel1.h = coords.y;
	buttonLv1Rect = {SCREEN_WIDTH / 2 - buttonLevel1.w / 2, 200, buttonLevel1.w, buttonLevel1.h};
	
	//Jugar Nivel 2
	Text buttonLevel2({ MENU_BUTTON_LVL2, "Play Level B", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(menuFont.id, buttonLevel2);
	coords = Renderer::Instance()->GetTextureSize(buttonLevel2.id);
	buttonLevel2.w = coords.x;
	buttonLevel2.h = coords.y;
	buttonLv2Rect = { SCREEN_WIDTH / 2 - buttonLevel2.w / 2, 200 + buttonLevel2.h, buttonLevel2.w, buttonLevel2.h };

	//Ranking
	Text buttonRanking({ MENU_BUTTON_RANKING, "Ranking", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(menuFont.id, buttonRanking);
	coords = Renderer::Instance()->GetTextureSize(buttonRanking.id);
	buttonRanking.w = coords.x;
	buttonRanking.h = coords.y;
	rankingRect = { SCREEN_WIDTH / 2 - buttonRanking.w / 2, 200 + 2 * buttonRanking.h, buttonRanking.w, buttonRanking.h };

	//Exit
	Text buttonExit({ MENU_BUTTON_EXIT, "Exit", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(menuFont.id, buttonExit);
	coords = Renderer::Instance()->GetTextureSize(buttonExit.id);
	buttonExit.w = coords.x;
	buttonExit.h = coords.y;
	exitRect = { SCREEN_WIDTH / 2 - buttonExit.w / 2, 200 + 3 * buttonExit.h, buttonExit.w, buttonExit.h };

	//Mute Sound
	Text buttonSound({ MENU_BUTTON_SOUND, "Mute Sound", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(menuFont.id, buttonSound);
	coords = Renderer::Instance()->GetTextureSize(buttonSound.id);
	buttonSound.w = coords.x;
	buttonSound.h = coords.y;
	soundRect = { SCREEN_WIDTH / 2 - buttonSound.w / 2, 200 + 4 * buttonSound.h, buttonSound.w, buttonSound.h };
}


Menu::~Menu()
{
}

void Menu::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage("background", sceneBackground);
	Renderer::Instance()->PushImage(MENU_BUTTON_LVL1, buttonLv1Rect);
	Renderer::Instance()->PushImage(MENU_BUTTON_LVL2, buttonLv2Rect);
	Renderer::Instance()->PushImage(MENU_BUTTON_RANKING, rankingRect);
	Renderer::Instance()->PushImage(MENU_BUTTON_EXIT, exitRect);
	Renderer::Instance()->PushImage(MENU_BUTTON_SOUND, soundRect);
	Renderer::Instance()->Render();
}

void Menu::Update()
{

}

void Menu::EventHandle()
{
	SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				currentSceneState = states::Exit;
				break;
			case SDL_MOUSEMOTION:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					//Ratolí sobre el botó Play	lvl1			
					if ((event.button.x > buttonLv1Rect.x) && (event.button.x < buttonLv1Rect.x + buttonLv1Rect.w) && (event.button.y > buttonLv1Rect.y) && (event.button.y < buttonLv1Rect.y + buttonLv1Rect.h))
					{
						currentSceneState = states::RunLV1;
					}
					//Ratolí sobre el botó Play	lvl2			
					if ((event.button.x > buttonLv2Rect.x) && (event.button.x < buttonLv2Rect.x + buttonLv2Rect.w) && (event.button.y > buttonLv2Rect.y) && (event.button.y < buttonLv2Rect.y + buttonLv2Rect.h))
					{
						currentSceneState = states::RunLV2;
					}
					//Ratolí sobre el botó Ranking			
					if ((event.button.x > rankingRect.x) && (event.button.x < rankingRect.x + rankingRect.w) && (event.button.y > rankingRect.y) && (event.button.y < rankingRect.y + rankingRect.h))
					{
						currentSceneState = states::GoTo_Ranking;
					}
					//Ratolí sobre el botó Exit			
					if ((event.button.x > exitRect.x) && (event.button.x < exitRect.x + exitRect.w) && (event.button.y > exitRect.y) && (event.button.y < exitRect.y + exitRect.h))
					{
						currentSceneState = states::Exit;
					}
					//Ratolí sobre el botó Mute Sound			
					if ((event.button.x > soundRect.x) && (event.button.x < soundRect.x + soundRect.w) && (event.button.y > soundRect.y) && (event.button.y < soundRect.y + soundRect.h))
					{
						currentSceneState = states::Exit;
					}
				}
				break;
			default: break;
			}
		}
	}
