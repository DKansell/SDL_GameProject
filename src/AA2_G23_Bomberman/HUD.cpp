#include "HUD.h"



HUD::HUD(Player &player1, Player &player2) :
	HUDRect({0, 0, 624, 80}),
	player1(&player1),
	player2(&player2)
{
	Font hudFont;
	hudFont.id = SAIYAN_80;
	hudFont.path = PATH_MENUFONT;
	hudFont.size = 25;
	Renderer::Instance()->LoadFont(hudFont);

	//Jugador 1
	Text textPlayer1({ "HUD_PLAYER1", "Player A", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(hudFont.id, textPlayer1);
	Vector2 coords = Renderer::Instance()->GetTextureSize(textPlayer1.id);
	player1Rect.w = coords.x;
	player1Rect.h = coords.y;
	player1Rect = { player1Rect.w, 0, player1Rect.w, player1Rect.h };

	//Jugador 2
	Text textPlayer2({ "HUD_PLAYER2", "Player B", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(hudFont.id, textPlayer2);
	coords = Renderer::Instance()->GetTextureSize(textPlayer2.id);
	player2Rect.w = coords.x;
	player2Rect.h = coords.y;
	player2Rect = { HUDRect.w - player2Rect.w, 0, player2Rect.w, player2Rect.h };

	//Score
	Text textScore({ "HUD_SCORE", "Score: ", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(hudFont.id, textScore);
	coords = Renderer::Instance()->GetTextureSize(textScore.id);
	scoreRect.w = coords.x;
	scoreRect.h = coords.y;
	scoreRect = { player1Rect.w, scoreRect.h, scoreRect.w, scoreRect.h };
	
	//Lives
	Text textLives({ "HUD_LIVES", "Lives: ", Color{ 76,0,153,0 } });
	Renderer::Instance()->LoadTextureText(hudFont.id, textLives);
	coords = Renderer::Instance()->GetTextureSize(textLives.id);
	livesRect.w = coords.x;
	livesRect.h = coords.y;
	livesRect = { player1Rect.w, 2 * livesRect.h, livesRect.w, livesRect.h };
}


HUD::~HUD()
{
}

void HUD::Draw()
{
	Renderer::Instance()->PushImage("HUD_PLAYER1", player1Rect);
	Renderer::Instance()->PushImage("HUD_PLAYER2", player2Rect);
	Renderer::Instance()->PushImage("HUD_SCORE", scoreRect);
	Renderer::Instance()->PushImage("HUD_LIVES", livesRect);
	Renderer::Instance()->PushImage("HUD_SCORE", { HUDRect.w - scoreRect.w, scoreRect.h, scoreRect.w, scoreRect.h });
	Renderer::Instance()->PushImage("HUD_LIVES", { HUDRect.w - livesRect.w, 2 * livesRect.h, livesRect.w, livesRect.h });
	
}