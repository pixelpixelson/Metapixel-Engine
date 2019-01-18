#pragma once
#include "../Vector/Vector2.h"

namespace CoreEngine
{
	class GameEngine;

	namespace States
	{
		class GameState;
	}

	namespace Objects
	{
		class GameEntity
		{
		public:
			GameEntity(Vector::Vector2 position);
			virtual ~GameEntity();

			Vector::Vector2 position;	
			virtual void Start(States::GameState const* state) = 0;
			virtual void Input(GameEngine& engine, float state) = 0;
			virtual void Update(States::GameState const* state, float step) = 0;
			virtual void Render(GameEngine& engine) = 0;
		};
	}
}