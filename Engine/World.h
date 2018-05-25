#pragma once

#include "Player.h"

class World
{
public:
	World() = default;

	void Update( class Keyboard& _kbd, float dt );

	Player& GetPlayer()noexcept;
	const Player& GetPlayer()const noexcept;
	bool IsOnGround( const Vec2f& _position, const float _height )noexcept;
	void Draw( class Graphics& _gfx );
public:
	static constexpr float gravity = 100.f;
private:
	Player player;
};

