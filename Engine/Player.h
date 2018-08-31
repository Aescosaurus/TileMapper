#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "TileMap.h"

// Works like top down now, but can be modified
//  to use platformer controls.
class Player
{
public:
	Player( const Vec2& pos );

	void Update( const Keyboard& kbd,
		const TileMap& map,float dt );
	void Draw( Graphics& gfx ) const;

	const Vec2& GetPos() const;
private:
	Vec2 pos;
	static constexpr Vei2 size = { 24,24 };
	static constexpr float speed = 140.0f;
};