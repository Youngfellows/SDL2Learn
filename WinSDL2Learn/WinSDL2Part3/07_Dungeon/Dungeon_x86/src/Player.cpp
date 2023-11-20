#include <Player.h>
#include <SpriteComponent.h>
#include <MoveComponent.h>
#include <Game.h>
#include "Setting.h"

namespace Dungeon
{
	Player::Player(Game *game) :
		GameObject(game)
	{
		SpriteComponent *sprite = new SpriteComponent(this, 100);
		//sprite->SetTexture(GetGame()->GetTexture("player"));
		sprite->SetTexture(GetGame()->GetTexture(Dungeon::Role::PLAYER));
		SetPosition(Vector2(288, 240));
		MoveComponent *moveComponent = new MoveComponent(this);
	}
}