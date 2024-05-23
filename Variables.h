#pragma once

#include <SDL_mixer.h>
#include <sstream>
#include "Texture.h"
#include "Constants.h"
#include "Button.h"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern Mix_Music *winner;
extern Mix_Music *loser;
extern Mix_Chunk *click;

extern TTF_Font *gGameOver;
extern TTF_Font *gPlayAgainWin;
extern TTF_Font *gPlayAgainLose;

extern SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
extern LTexture gButtonSpriteSheetTexture;

extern LTexture gWinningTexture;
extern LTexture gBackgroundTexture;

extern LTexture gTextTexture;
extern LTexture gMineLeftTexture;
extern LTexture gPlayAgainWinTexture;
extern LTexture gPlayAgainLoseTexture;

extern int countMineLeft;
extern int countTileLeft;
extern bool gameOver;
extern bool isWinning;

extern stringstream mineLeft;
extern int board[ROW_SIZE][COLUMN_SIZE];
extern int sBoard[ROW_SIZE][COLUMN_SIZE];




