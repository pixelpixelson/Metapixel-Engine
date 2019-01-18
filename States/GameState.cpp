#include "../GameEngine.h"
#include "../Vector/Vector2.h"
#include "GameState.h"

CoreEngine::States::GameState::GameState()
{
}

CoreEngine::States::GameState::~GameState()
{
}

void CoreEngine::States::GameState::Tick(GameEngine& engine, float delta_time)
{
	static float physics_time_accumulator = 0.0f;
	physics_time_accumulator += delta_time;

	// Update the game 30 times per second
	constexpr float PhysicsTimeStep = 1.0f / 30.0f;
 
	Input(engine, PhysicsTimeStep);

	// The game engine uses a Time Step system to fix lag
	while (physics_time_accumulator >= PhysicsTimeStep)
	{
		physics_time_accumulator -= PhysicsTimeStep;
		
		Update(engine, PhysicsTimeStep);
	}

	Render(engine);
}

CoreEngine::Vector::Vector2 CoreEngine::States::GameState::ScreenDimensions() const
{
	return Vector::Vector2(screen_width, screen_height);
}

void CoreEngine::States::GameState::ScreenDimensions(float w, float h)
{
	screen_width = w;
	screen_height = h;
}
