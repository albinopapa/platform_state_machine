#pragma once

#include "PlayerState.h"
#include "Vector.h"
#include <memory>

class Player
{
public:
	Player();
	void Update( class Keyboard& _kbd, class World& _world, float dt );
	Vec2f GetPosition()const;
	Vec2f GetVelocity()const;
	void SetPosition( Vec2f _position );
	void SetVelocity( Vec2f _velocity );
	void TransitionNext( std::unique_ptr<PlayerState> _next_state );
	void Draw( class Graphics& _gfx );
public:
	static constexpr float speed = 300.f;
	static constexpr float height = 32.f;
	static constexpr float jump_height = 25.f;
private:
	std::unique_ptr<PlayerState> state, next_state;
	Vec2f position = { 400.f, 500.f }, velocity{ 0.f, 0.f };
};

