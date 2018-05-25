#pragma once
class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState();

	virtual void Process( class Player& _player, class Keyboard& _kbd, class World& _world, float dt ) = 0;
};

