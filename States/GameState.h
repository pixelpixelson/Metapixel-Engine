#pragma once

namespace CoreEngine
{
	class GameEngine;

	namespace States
	{
		class GameState
		{
		public:
			GameState();
			virtual ~GameState();
			void Tick(GameEngine& engine, float delta_time);

			virtual void Start(GameEngine& engine) = 0;
			virtual void Exit(GameEngine& engine) = 0;
		protected:
			virtual void Input(GameEngine& engine, float time_step) = 0;
			virtual void Update(GameEngine& engine, float time_step) = 0;
			virtual void Render(GameEngine& engine) = 0;
		};
	}
}