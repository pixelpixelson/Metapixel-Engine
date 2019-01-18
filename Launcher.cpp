#include "GameEngine.h"

int main()
{
	using namespace CoreEngine;
	GameEngine engine;
	if (engine.Construct(360, 240, 1, 1))
	{
		engine.Start();
		return 0;
	}

	// Something terrible happened with construction
	std::cout << "Couldnt initialize the Game Engine. Check your video card drivers.\n";
	std::cin.peek();
	return 1;
}