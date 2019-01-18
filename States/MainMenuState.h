#pragma once
#include "GameState.h"
#include <string>
#include <vector>
#include <memory>

namespace CoreEngine::States
{
	class MainGameState;

	namespace MainMenu
	{
		class MainMenuOption
		{
		public:
			MainMenuOption(const std::string text);
			virtual ~MainMenuOption();
			std::string option_text;
			std::function<void(GameEngine& engine)> func;
		};
	}

	class MainMenuState : public GameState
	{
	public:
		MainMenuState(std::vector<std::shared_ptr<MainMenu::MainMenuOption>>& options, const std::string& name);
		~MainMenuState();
		MainMenuState();

		std::string name = "Epic Game";
		void Start(GameEngine& engine) override;
		void Exit(GameEngine& engine) override;
	protected:
		void Input(GameEngine& engine,  float time_step) override;
		void Update(GameEngine& engine, float time_step) override;
		void Render(GameEngine& engine) override;

		std::vector <std::shared_ptr<MainMenu::MainMenuOption>> options;
		int option_selection = 0;
	};

	
}