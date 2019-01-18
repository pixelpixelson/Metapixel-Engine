#pragma once
#include "olcPixelGameEngine.h"
#include "States/GameState.h"
#include <stack>

namespace CoreEngine
{
	class GameEngine : public olc::PixelGameEngine
	{
	public:
		GameEngine();
		~GameEngine();


		void PushStateRequest(States::GameState* state);
		void PopStateRequest();

		
	protected:

		bool OnUserCreate() override;
		bool OnUserUpdate(float time) override;
	private:
		void PushState(States::GameState* state);
		void PopState();

		std::vector<std::unique_ptr<States::GameState>> states;
	
		struct StateChangeRequest
		{
			enum class Kind
			{
				Pop,
				Push
			} kind;
			
			union
			{
				States::GameState* state;
			} push;
		};

		std::stack<StateChangeRequest> state_change_requests;
	
	};
}