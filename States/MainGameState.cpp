#include "../Objects/EntityShip.h"
#include "../GameEngine.h"
#include "MainGameState.h"
#include "MainMenuState.h"


using namespace CoreEngine;

void CoreEngine::States::MainGameState::Start(GameEngine & engine)
{
	using namespace Vector;
	using namespace Objects;

	engine.Clear(olc::BLACK);

	// add ships
	SpawnEntity(new Objects::EntityShip(Vector2(0.0f, engine.ScreenHeight() / 2.0f), EntityShip::Kind::Player));
	SpawnEntity(new Objects::EntityShip(Vector2(engine.ScreenWidth() - 30.0f, engine.ScreenHeight() / 2.0f), EntityShip::Kind::Enemy));
}

void CoreEngine::States::MainGameState::Exit(GameEngine & engine)
{
}

std::unique_ptr<Objects::GameEntity>& CoreEngine::States::MainGameState::SpawnEntity(Objects::GameEntity * entity)
{
	entity->Start(this);
	entities.push_back(std::unique_ptr<Objects::GameEntity>(entity));
	return entities.back();
}

void CoreEngine::States::MainGameState::Input(GameEngine & engine, float time_step)
{
	// Escape pops the stack, returning
	// us to the main menu
	if (engine.GetKey(olc::ESCAPE).bPressed)
	{
		engine.PopStateRequest();
	}

	for (auto& entity : entities)
	{
		entity->Input(engine, time_step);
	}
}

void CoreEngine::States::MainGameState::Update(GameEngine& engine, float time_step)
{
	for (auto iterator = entities.begin(); iterator < entities.end(); ++iterator)
	{
		if(iterator->get()->marked_for_destruction)
		{
			iterator->get()->Destroy(this);
			iterator = entities.erase(iterator);
		}
		else
		{
			iterator->get()->Update(this, time_step);
		}
	}
}

void CoreEngine::States::MainGameState::Render(GameEngine& engine)
{
	engine.Clear(olc::BLACK);
	engine.DrawString(0, 0, "Main Game State, Escape to return to menu");

	for (auto& entity : entities)
	{
		entity->Render(engine);
	}
}
