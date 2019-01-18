#pragma once
#include "GameEntity.h"

namespace CoreEngine::Objects
{
	class EntityShipBullet : public GameEntity
	{
	public:
		EntityShipBullet(Vector::Vector2 position, float speed);
		float speed = 10.0f;

		Vector::Vector2 position;
		void Start(States::GameState const* state);
		void Input(GameEngine& engine, float state);
		void Update(States::GameState const* state, float step);
		void Render(GameEngine& engine);
	};
}