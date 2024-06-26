#include <ctime>
#include "Button.h"

void reveal(int i, int j)
{
    if (sBoard[i][j] == 10 || sBoard[i][j] == 11)
    {
        if (sBoard[i][j] == 11)
        {
            countMineLeft++;
        }
        sBoard[i][j] = board[i][j];
        countTileLeft--;
        if (sBoard[i][j] == 0)
        {
            if (i < ROW_SIZE - 1)
                reveal(i + 1, j);
            if (i > 0)
                reveal(i - 1, j);
            if (j < COLUMN_SIZE - 1)
                reveal(i, j + 1);
            if (j > 0)
                reveal(i, j - 1);
            if (i > 0 && j > 0)
                reveal(i - 1, j - 1);
            if (i < ROW_SIZE - 1 && j < COLUMN_SIZE - 1)
                reveal(i + 1, j + 1);
            if (i > 0 && j < COLUMN_SIZE - 1)
                reveal(i - 1, j + 1);
            if (i < ROW_SIZE - 1 && j > 0)
                reveal(i + 1, j - 1);
        }
    }
}

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;
}

void LButton::setPosition( int x, int y )
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent( SDL_Event* e )
{
    //Check mouse
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		int x, y;
		SDL_GetMouseState( &x, &y );

        int i = (y - DISTANCE_BETWEEN)/TILE_SIZE;
        int j = (x - DISTANCE_BETWEEN)/TILE_SIZE;

		bool inside = true;

		if( x < mPosition.x )
		{
			inside = false;
		}
		else if( x > mPosition.x + TILE_SIZE )
		{
			inside = false;
		}
		else if( y < mPosition.y )
		{
			inside = false;
		}
		else if( y > mPosition.y + TILE_SIZE )
		{
			inside = false;
		}

		if ( inside )
		{
			if ( e->type == SDL_MOUSEBUTTONDOWN )
            {
				Mix_PlayChannel(-1, click, 0);

				switch ( e->button.button )
				{
                    case SDL_BUTTON_LEFT:
                    {
                        reveal(i, j);
                        if (board[i][j] == 9)
                        {
                            gameOver = true;
                        }
                        break;
                    }
                    case SDL_BUTTON_RIGHT:
                    {
                        if (sBoard[i][j] >= 10)
                        {
                            if (sBoard[i][j] == 10)
                            {
                                if (countMineLeft == 0) break;
                                sBoard[i][j] = 11;
                                countMineLeft--;
                            }
                            else
                            {
                                sBoard[i][j] = 10;
                                countMineLeft++;
                            }
                        }
                        break;
                    }
				}
            }
		}
	}
}

void LButton::render(int i, int j)
{
	gButtonSpriteSheetTexture.render( mPosition.x, mPosition.y, &gSpriteClips[ sBoard[i][j] ] );
}
