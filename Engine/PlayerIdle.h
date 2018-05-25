#pragma once
#include "PlayerState.h"
class PlayerIdle :
	public PlayerState
{
public:
	void Process( class Player& _player, class Keyboard& _kbd, class World& _world, float dt )override;
};

