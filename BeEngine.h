#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "States/State.h"

class BeEngine
{
public:
	//Calls the other constructor with settingsFile="engine.json"
	BeEngine();
	//Loads engine with settings from settingsFile
	BeEngine(const std::string& settingsFile);
	~BeEngine();
private:
	//container for all game-loop logic
	void gameLoop();
	//provides user inputs to the InputManager class
	void manageInputs();
	//update game state
	void updateState(sf::Time dt);
	//display everything
	void render();
	//save the current game state
	void saveGame();

	sf::RenderWindow window;
	State* state;
	sf::Clock clock;

	bool exit = false;

	//Helper Functions for States
public:
	sf::Vector2u getWindowResolution();
	sf::Vector2i getMousePosition(bool relativeToWindow = true);
	sf::RenderWindow& getWindow();
};

