#pragma once
#include "PlayerState.h"
class PlayerRunning :
	public PlayerState
{
public:
	void Process( class Player& _player, class Keyboard& _kbd, class World& _world, float dt )override;
};

