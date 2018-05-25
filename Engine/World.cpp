#include "Graphics.h"
#include "Keyboard.h"
#include "World.h"

void			World::Update( Keyboard& _kbd, float dt )
{
	player.Update( _kbd, *this, dt );
	// For now clamp to screen edges and ground plane at 500.f y-pixel
	{
		auto pos = player.GetPosition();
		pos.x = std::max( 0.f, std::min( float( Graphics::ScreenWidth ) - 16.f, pos.x ) );
		pos.y = std::max( 0.f, std::min( 500.f - Player::height, pos.y ) );
		player.SetPosition( pos );
	}
}

Player&			World::GetPlayer()noexcept
{
	return player;
}

const Player&	World::GetPlayer()const noexcept
{
	return player;
}

bool			World::IsOnGround( const Vec2f& _position, const float _height )noexcept
{
	return _position.y + _height >= 500.f;
}

void			World::Draw( class Graphics& _gfx )
{
	player.Draw( _gfx );
}