#include "ChiliWin.h"
#include "PlayerRunning.h"
#include "PlayerJumping.h"
#include "PlayerIdle.h"
#include "Keyboard.h"
#include "World.h"



void PlayerRunning::Process( class Player& _player, class Keyboard& _kbd, class World& _world, float dt )
{
	auto vel = _player.GetVelocity();
	bool keyPressed = false;
	if( _kbd.KeyIsPressed( VK_LEFT ) || _kbd.KeyIsPressed( VK_RIGHT ) )
	{
		vel.x = ( _kbd.KeyIsPressed( VK_LEFT ) ? -1.f : 1.f ) * Player::speed * dt;
		keyPressed = true;
	}
	if( _kbd.KeyIsPressed( VK_SPACE ) )
	{
		vel.y -= Player::jump_height;
		_player.TransitionNext( std::make_unique<PlayerJumping>() );
		keyPressed = true;
	}
	if( !keyPressed )
	{
		_player.TransitionNext( std::make_unique<PlayerIdle>() );
	}

	_player.SetVelocity( vel );

}