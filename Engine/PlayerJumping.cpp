#include "ChiliWin.h"
#include "Player.h"
#include "PlayerJumping.h"
#include "PlayerIdle.h"
#include "PlayerRunning.h"
#include "Keyboard.h"
#include "World.h"



void PlayerJumping::Process( Player& _player, Keyboard& _kbd, World& _world, float dt )
{
	auto vel = _player.GetVelocity();
	if( _kbd.KeyIsPressed( VK_LEFT ) || _kbd.KeyIsPressed( VK_RIGHT ) )
	{
		vel.x = ( _kbd.KeyIsPressed( VK_LEFT ) ? -1.f : 1.f ) * Player::speed * dt;
		_player.SetVelocity( vel );
	}

	if( _world.IsOnGround( _player.GetPosition(), Player::height ) )
	{
		if( _kbd.KeyIsPressed( VK_LEFT ) || _kbd.KeyIsPressed( VK_RIGHT ) )
		{
			_player.TransitionNext( std::make_unique<PlayerRunning>() );
		}
		else
		{
			_player.TransitionNext( std::make_unique<PlayerIdle>() );
		}
	}
}