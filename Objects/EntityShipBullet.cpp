#include "../GameEngine.h"
#include "EntityShipBullet.h"

CoreEngine::Objects::EntityShipBullet::EntityShipBullet(Vector::Vector2 position, float speed) : 
	CoreEngine::Objects::GameEntity(position), speed{ speed }
{
}

void CoreEngine::Objects::EntityShipBullet::Start(States::GameState const * state)
{
}

void CoreEngine::Objects::EntityShipBullet::Input(GameEngine & engine, float state)
{
}

void CoreEngine::Objects::EntityShipBullet::Update(States::GameState const* state, float step)
{

	if (position.x < 0) marked_for_destruction = true;
	if (position.x > state->ScreenDimensions().x) marked_for_destruction = true;
	position.x += speed * step;
}

void CoreEngine::Objects::EntityShipBullet::Render(GameEngine & engine)
{
	engine.FillCircle(position.x, position.y, 10, olc::YELLOW);
}
