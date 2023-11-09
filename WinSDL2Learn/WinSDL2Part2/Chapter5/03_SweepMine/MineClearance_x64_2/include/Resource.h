#ifndef _DUNGEON_RESOURCE_H_
#define _DUNGEON_RESOURCE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{
	class Resource
	{
	private:
		SDL_Surface *mCursorSurface;
		SDL_Cursor *mCursor;
		SDL_Texture *mCursorTexture;//鼠标资源
		SDL_Texture *mBackgroundTexture;//背景资源
		SDL_Texture *mPlayerTexture;//玩家
		SDL_Texture *mMineTexture;//雷
		SDL_Texture *mGroundTexture;//场地
		SDL_Texture *mWallTexture;//墙壁

	public:
		Resource();
		~Resource();
		SDL_bool load(SDL_Renderer *renderer);
		SDL_Texture *GetCursorTexture();
		SDL_Surface *GetCursorSurface();
		SDL_Cursor *GetCursor();
		SDL_Texture *GetBackgroundTexture();
		SDL_Texture *GetPlayerTexture();
		SDL_Texture *GetMineTexture();
		SDL_Texture *GetGroundTexture();
		SDL_Texture *GetWallTexture();
		void Unload();

	private:
		SDL_bool LoadCursor(const char *file, SDL_Renderer *renderer);
		SDL_bool LoadBackground(const char *file, SDL_Renderer *renderer);
		SDL_bool LoadPlayer(const char *file, SDL_Renderer *renderer);
		SDL_bool LoadMine(const char *file, SDL_Renderer *renderer);
		SDL_bool LoadGround(const char *file, SDL_Renderer *renderer);
		SDL_bool LoadWall(const char *file, SDL_Renderer *renderer);
	};
}
#endif // !_DUNGEON_RESOURCE_H_

