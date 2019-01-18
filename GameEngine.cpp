#include <vector>
#include <memory>
#include "GameEngine.h"
#include "States/MainMenuState.h"

CoreEngine::GameEngine::GameEngine()
{
}

CoreEngine::GameEngine::~GameEngine()
{
}

void CoreEngine::GameEngine::PushStateRequest(States::GameState * state)
{
	state_change_requests.push({StateChangeRequest::Kind::Push, state});
}

void CoreEngine::GameEngine::PopStateRequest()
{
	state_change_requests.push({ StateChangeRequest::Kind::Pop, 0});
}

void CoreEngine::GameEngine::PushState(States::GameState* state)
{
	state->Start(*this);
	states.push_back(std::unique_ptr <States::GameState>(state));
}

void CoreEngine::GameEngine::PopState()
{
	states.back()->Exit(*this);
	states.pop_back();
}

bool CoreEngine::GameEngine::OnUserCreate()
{
	PushState(new States::MainMenuState());
	return true;
}

bool CoreEngine::GameEngine::OnUserUpdate(float time)
{
	while (!state_change_requests.empty())
	{
		auto request = state_change_requests.top();
		switch (request.kind)
		{
		case StateChangeRequest::Kind::Push:
			PushState(request.push.state);
			break;
		case StateChangeRequest::Kind::Pop:
			PopState();
			break;
		}
		state_change_requests.pop();
	}

	if (!states.empty())
	{
		states.back()->Tick(*this, time);
	}
	else
	{
		return false;
	}
	return true;
}
