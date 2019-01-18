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

			// Called in the game loop, do not call this to destroy the object,
			// instead set marked_for_destruction to true. The object
			// will be destoyed *next frame*
			virtual void Destroy(States::GameState const* state);
			bool marked_for_destruction = false;
		};
	}
}