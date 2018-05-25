#include "Graphics.h"
#include "Player.h"
#include "PlayerIdle.h"
#include "World.h"

Player::Player()
	:
	state( std::make_unique<PlayerIdle>() )
{}
void  Player::Update( class Keyboard& _kbd, class World& _world, float dt )
{
	if( next_state )
		state = std::move( next_state );
	
	state->Process( *this, _kbd, _world, dt );

	velocity.y += World::gravity * dt;
	position += velocity;
	if( _world.IsOnGround( position, height ) )
	{
		position.y = 500.f - height;
		velocity.y = 0.f;
	}
}
Vec2f Player::GetPosition()const
{
	return position;
}
Vec2f Player::GetVelocity()const
{
	return velocity;
}
void  Player::SetPosition( Vec2f _position )
{
	position = _position;
}
void  Player::SetVelocity( Vec2f _velocity )
{
	velocity = _velocity;
}
void  Player::TransitionNext( std::unique_ptr<PlayerState> _next_state )
{
	next_state = std::move( _next_state );
}
void Player::Draw( Graphics& _gfx )
{
	_gfx.FillRect(
		int( position.x ),
		int( position.y ),
		int( position.x + 16.f ),
		int( position.y + height ),
		Colors::White
	);
}