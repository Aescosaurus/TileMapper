#include "Player.h"

Player::Player( const Vec2& pos )
	:
	pos( pos )
{
}

void Player::Update( const Keyboard& kbd,
	const TileMap& map,float dt )
{
	Vec2 moveDir = { 0.0f,0.0f };
	if( kbd.KeyIsPressed( 'W' ) )
	{
		--moveDir.y;
	}
	if( kbd.KeyIsPressed( 'S' ) )
	{
		++moveDir.y;
	}
	if( kbd.KeyIsPressed( 'A' ) )
	{
		--moveDir.x;
	}
	if( kbd.KeyIsPressed( 'D' ) )
	{
		++moveDir.x;
	}
	moveDir = moveDir.GetNormalized() * speed * dt;

	if( map.GetTileAt( pos + Vec2{ moveDir.x,0.0f } ) ==
		TileMap::TileType::Empty )
	{
		pos.x += moveDir.x;
	}
	if( map.GetTileAt( pos + Vec2{ 0.0f,moveDir.y } ) ==
		TileMap::TileType::Empty )
	{
		pos.y += moveDir.y;
	}
}

void Player::Draw( Graphics& gfx ) const
{
	const auto drawPos = pos - Vec2( size ) / 2.0f;
	gfx.DrawRect( drawPos.x,drawPos.y,
		size.x,size.y,Colors::Red );
}

const Vec2& Player::GetPos() const
{
	return( pos );
}
