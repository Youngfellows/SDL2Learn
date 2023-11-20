#include <InputComponent.h>
#include <MoveComponent.h>
#include <GameObject.h>
#include <SDL2/SDL_scancode.h>

namespace Dungeon
{
	InputComponent::InputComponent(GameObject *gameObject) :
		Component(gameObject)
	{
	}

	/*
	* 改变组件的方向
	*	向左: A/左方向键
	*	向右: D/右方向键
	*	向上: W/上方向键
	*	向下: S/下方向键
	*/
	void InputComponent::ProcessInput(const uint8_t *state)
	{
		MoveComponent *mc = mGameObject->GetComponent<MoveComponent>();
		if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP])
		{
			mc->SetDir(Vector2::NY);
		}
		else if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN])
		{
			mc->SetDir(Vector2::Y);
		}
		else if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT])
		{
			mc->SetDir(Vector2::NX);
		}
		else if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT])
		{
			mc->SetDir(Vector2::X);
		}
		else
		{
			mc->SetDir(Vector2::Zero);
		}
	}

}