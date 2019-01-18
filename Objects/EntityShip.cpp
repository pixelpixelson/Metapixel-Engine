#include "../GameEngine.h"
#include "../States/GameState.h"
#include "EntityShip.h"

CoreEngine::Objects::EntityShip::EntityShip(Vector::Vector2 position, Kind kind) : 
	CoreEngine::Objects::GameEntity(position), kind{ kind }
{
}

void CoreEngine::Objects::EntityShip::Start(States::GameState const * state)
{
}

void CoreEngine::Objects::EntityShip::Input(GameEngine & engine, float step)
{
	if (kind == Kind::Player)
	{
		if (engine.GetKey(olc::UP).bHeld)
		{
			// Move up
			position.y -= step * 10.0f;
		}
		else if (engine.GetKey(olc::DOWN).bHeld)
		{
			// Move down
			position.y += step * 10.0f;
		}

		if (engine.GetKey(olc::SPACE).bHeld)
		{
			// Enable firing
			marked_for_destruction = true;
		}
	}
}

void CoreEngine::Objects::EntityShip::Update(States::GameState const * state, float step)
{
	if (position.y < 50.0f)  position.y = 50.0f;
	if (position.y > 150.0f) position.y = 150.0f;
}

void CoreEngine::Objects::EntityShip::Render(GameEngine & engine)
{
	olc::Pixel color = kind == Kind::Enemy ? olc::RED : olc::GREEN;
	engine.FillRect(position.x, position.y, 30.0f, 19.0f,color);
}
