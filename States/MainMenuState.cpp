#include "MainGameState.h"
#include "../Rendering/Transformer.h"
#include "../Rendering/BasicTransformations.h"

#include "../GameEngine.h"
#include "MainMenuState.h"

CoreEngine::States::MainMenuState::MainMenuState() : GameState()
{
	using namespace MainMenu;
	


	/////////////////////
	// Menu Diagram
	/////////////////////

	// GAME NAME
	//---------------------     OPTIONS
	//  Play  -> (To game)|  --------------------
	//  Options            ->       Placeholder |
	//  Exit -> (Quit)    |<-       Return      |
	//---------------------  --------------------


	// This looks complicated but its simple when you
	// realise how I did this.

	auto playFunc = [](GameEngine& engine)
	{
		// Pressing play pushes the Main Game onto the
		// stack, making it the current State in the
		// next Game Loop
		engine.PushStateRequest(new MainGameState());
	};

	auto optionsFunc = [](GameEngine& engine)
	{
		std::cout << "Options\n";

		auto options_options = std::vector<std::shared_ptr<MainMenuOption>>();
		auto placeholder = std::make_shared<MainMenuOption>(MainMenuOption("Placeholder Option"));

		// When the place holder option is selected, do nothing.
		placeholder->func = [](GameEngine& engine) { std::cout << "A placeholder option\n"; };
		options_options.push_back(placeholder);

		// This function will pop the game state so we return back
		// to the main menu
		auto return_to_main_menu = std::make_shared<MainMenuOption>(MainMenuOption("Return"));
		return_to_main_menu->func = [](GameEngine& engine) {engine.PopStateRequest(); };
		options_options.push_back(return_to_main_menu);

		// Push the options menu onto the stack
		engine.PushStateRequest(new MainMenuState(options_options,"Options"));
	};

	auto quitFunc = [](GameEngine& engine)
	{
		// Since we are on the first stack
		// which is the Main Menu,
		// popping would close the game
		engine.PopStateRequest();
	};


	// Add all main menu options
	auto play = std::make_shared<MainMenuOption>(MainMenuOption("Play"));
	play->func = playFunc;
	options.push_back(play);


	auto option = std::make_shared<MainMenuOption>(MainMenuOption("Options"));
	option->func = optionsFunc;
	options.push_back(option);


	auto quit = std::make_shared<MainMenuOption>(MainMenuOption("Exit Game"));
	quit->func = quitFunc;
	options.push_back(quit);
}

CoreEngine::States::MainMenuState::MainMenuState(std::vector<std::shared_ptr<MainMenu::MainMenuOption>>& options, const std::string& name) : options{ options }, name{ name }
{
}

CoreEngine::States::MainMenuState::~MainMenuState()
{
}

void CoreEngine::States::MainMenuState::Start(GameEngine & engine)
{

}

void CoreEngine::States::MainMenuState::Exit(GameEngine & engine)
{
}

void CoreEngine::States::MainMenuState::Input(GameEngine& engine, float time_step)
{
	// Basic NES style menu system

	if (engine.GetKey(olc::UP).bPressed)
	{
		--option_selection;
	}
	else if (engine.GetKey(olc::DOWN).bPressed)
	{
		++option_selection;
	}

	if (option_selection < 0) option_selection = options.size() - 1;
	else if (option_selection > options.size() - 1) option_selection = 0;

	if (engine.GetKey(olc::RIGHT).bPressed)
	{
		options.at(option_selection)->func(engine);
	}
}

void CoreEngine::States::MainMenuState::Update(GameEngine& engine, float time)
{
	// The menu is just input and rendering.
	// No update functionality
}

void CoreEngine::States::MainMenuState::Render(GameEngine & engine)
{
	engine.Clear(olc::BLACK);

	using namespace Rendering::Transform;
	using namespace Vector;

	Transformer transformer;
	transformer.PushTransformation(new Translate(Vector2(engine.ScreenWidth() / 2.0f - 50.0f ,engine.ScreenHeight() / 2 - 25.0f)));
	
	const Vector2 menu_offset(0.0f, 0.0f);
	const Vector2 menu_base_position = transformer.Transform(menu_offset);
	transformer.PopTransformation();
	
	engine.DrawString(menu_base_position.x - 25.0f, menu_base_position.y - 30.0f, name ,olc::YELLOW,2);

	float size = 0.0f;

	for (auto option : options)
	{
		float sze = option->option_text.size() * 8 + 32.0f;
		size = size < sze ? sze : size;
	}

	engine.DrawRect(menu_base_position.x - 30, menu_base_position.y, size + 30, options.size() * 8 + 36);

	transformer.PushTransformation(new Translate(Vector2(0.0f, 10.0f)));

	Vector2 item_location;

	for (int option = 0; option < options.size(); ++option)
	{	
		transformer.PushTransformation(new Translate(Vector2(0.0f, 8.0f)));
		item_location = transformer.Transform(menu_base_position);
		transformer.PopTransformation();

		float offset_x = option == option_selection ? 2.0f : 0.0f;


		if (option == option_selection)
		{

			// Fiddle around with positions for the triangle
			item_location.y += 4.0f;
			item_location.y += option * 8.0f;
			
			item_location.x -= 10.0f;
			engine.FillTriangle(item_location.x - 10.0f, item_location.y + 5.0f, item_location.x, item_location.y, item_location.x - 10.0f, item_location.y - 5.0f, olc::YELLOW);
			item_location.x += 10.0f;
			item_location.y -= option * 8.0f;
			item_location.y -= 4.0f;
		}

		engine.DrawString((item_location.x + offset_x), item_location.y + (option * 8), options.at(option).get()->option_text, option == option_selection ? olc::CYAN : olc::WHITE);
	}

	transformer.PushTransformation(new Translate(Vector2(-10.0f, options.size() * 8.0f + 16.0f)));
	const Vector2 credit = transformer.Transform(item_location);
	engine.DrawString(credit.x, credit.y, "Made by Pixel");
}

CoreEngine::States::MainMenu::MainMenuOption::MainMenuOption(const std::string text) : 
	option_text{ text }
{
}

CoreEngine::States::MainMenu::MainMenuOption::~MainMenuOption()
{
}