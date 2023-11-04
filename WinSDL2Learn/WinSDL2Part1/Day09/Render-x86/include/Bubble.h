#ifndef  _DUNGEON_POINT_H_
#define _DUNGEON_POINT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct BubbleData
	{
		Uint32 color;//颜色
		float x;
		float y;
		float speedX;
		float speedY;
		SDL_FRect border;//边界
		float angel;
		SDL_Texture *photo;
		SDL_FRect dest;//绘制区域
		SDL_bool move;
	}BubbleData;
}

namespace Dungeon
{
	class Bubble
	{
	private:
		const float WIDTH_HEIGHT = 30;

	public:
		BubbleData *mBubbleData;

	public:
		Bubble(Resource *resource, Uint32 color, SDL_FRect border);
		~Bubble();
		void Draw(Resource *resource, SDL_Renderer *renderer);
		void MouseMove(SDL_FPoint point);
		void SetMouseMove(SDL_bool move);
	};
}
#endif // ! _DUNGEON_POINT_H_

