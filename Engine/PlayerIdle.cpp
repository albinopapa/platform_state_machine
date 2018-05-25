#include "ChiliWin.h"
#include "PlayerIdle.h"
#include "PlayerJumping.h"
#include "PlayerRunning.h"
#include "Keyboard.h"
#include "World.h"



void PlayerIdle::Process( class Player& _player, class Keyboard& _kbd, class World& _world, float dt )
{
	auto vel = _player.GetVelocity();
	if( _kbd.KeyIsPressed( VK_LEFT ) || _kbd.KeyIsPressed( VK_RIGHT ) )
	{
		vel.x = ( _kbd.KeyIsPressed( VK_LEFT ) ? -1.f : 1.f ) * Player::speed * dt;
		_player.TransitionNext( std::make_unique<PlayerRunning>() );
	}
	if( _kbd.KeyIsPressed( VK_SPACE ) )
	{
		vel.y -= Player::jump_height;
		_player.TransitionNext( std::make_unique<PlayerJumping>() );
	}

	// Causes drag, so player slows down if no key presses
	vel.x *= .8f;
	_player.SetVelocity( vel );
}