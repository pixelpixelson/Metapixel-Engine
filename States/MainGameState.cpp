#include "../GameEngine.h"
#include "MainGameState.h"
#include "MainMenuState.h"

using namespace CoreEngine;

void CoreEngine::States::MainGameState::Start(GameEngine & engine)
{
	engine.Clear(olc::BLACK);
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
	for (auto& entity : entities)
	{
		entity->Update(this, time_step);
	}
}

void CoreEngine::States::MainGameState::Render(GameEngine& engine)
{
	engine.Clear(olc::BLACK);


	// Just put random garbage to the screen
	for (int i = 0; i < 3; ++i)
		switch (rand() % 3)
		{
		case 0:
			engine.FillTriangle(
				rand() % engine.ScreenWidth(),
				rand() % engine.ScreenHeight(),
				rand() % engine.ScreenWidth(),
				rand() % engine.ScreenHeight(),
				rand() % engine.ScreenWidth(),
				rand() % engine.ScreenHeight(),
				olc::Pixel(rand() % 256, rand() % 256, rand() % 256)
			);
			break;
		case 1:
			engine.FillRect(
				rand() % engine.ScreenWidth(),
				rand() % engine.ScreenHeight(),
				rand() % engine.ScreenWidth(),
				rand() % engine.ScreenHeight(),
				olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
			break;
		case 2:
			engine.FillCircle(
				rand() % engine.ScreenWidth(),
				rand() % engine.ScreenHeight(),
				rand() % 50,
				olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
			break;
		}
	

	engine.DrawString(0, 0, "Main Game State, Escape to return to menu");

	for (auto& entity : entities)
	{
		entity->Render(engine);
	}
}
