#pragma once
#include "GameState.h"
#include "../Objects/GameEntity.h"
#include <string>
#include <vector>
#include <memory>

namespace CoreEngine::States
{
	class MainGameState : public GameState
	{
	public:
		void Start(GameEngine& engine) override;
		void Exit(GameEngine& engine) override;

		// Spawn an entity to the game state
		std::unique_ptr<Objects::GameEntity>& SpawnEntity(Objects::GameEntity* entity);

	protected:
		void Input(GameEngine& engine, float time_step) override;
		void Update(GameEngine& engine, float time_step) override;
		void Render(GameEngine& engine) override;

		std::vector<std::unique_ptr<Objects::GameEntity>> entities;
	};
}