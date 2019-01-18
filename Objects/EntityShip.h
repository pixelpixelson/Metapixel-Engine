#pragma once
#include "GameEntity.h"

namespace CoreEngine::Objects
{
	class EntityShip : public GameEntity
	{
	public:
		enum class Kind
		{
			Player,
			Enemy
		} kind;

		EntityShip(Vector::Vector2 position, Kind kind);
		float health = 100.0f;

		void Start(States::GameState const* step) override;
		void Input(GameEngine& engine, float step) override;
		void Update(States::GameState const* state, float step) override;
		void Render(GameEngine& engine) override;
	};
}
