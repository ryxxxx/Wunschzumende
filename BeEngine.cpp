#include "BeEngine.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include "States/ShaderTest.h"
#include "States/MovementTest.h"

BeEngine::BeEngine() : BeEngine("resources/json/engine.json") {}

BeEngine::BeEngine(const std::string& settingsFile)
{
	std::ifstream iSettings{ settingsFile };
	nlohmann::json jsonSettings;
	iSettings >> jsonSettings;

	sf::VideoMode videoMode{ jsonSettings["resolution"][0].get<unsigned int>(),jsonSettings["resolution"][1].get<unsigned int>() };
	std::string title = jsonSettings["title"].get<std::string>();


	window.create(videoMode, title, sf::Style::None);
	window.setVerticalSyncEnabled(true);

	state = new MovementTest;
	state->load(this);

	gameLoop();
}

BeEngine::~BeEngine() 
{
	saveGame();
	delete state;
}

void BeEngine::gameLoop() 
{
	sf::Time currentTime = clock.getElapsedTime();
	while (!exit)
	{
		sf::Time newTime = clock.getElapsedTime();
		sf::Time dt = newTime - currentTime;
		currentTime = newTime;
		manageInputs();
		updateState(dt);
		render();
	}
}

void BeEngine::manageInputs() 
{
	//reset previous input
	/*
	Input::l_mouseClicked = false;
	Input::r_mouseClicked = false;
	Input::l_mouseReleased = false;
	Input::r_mouseReleased = false;
	*/

	sf::Event e;
	while (window.pollEvent(e))
	{
		//window close
		if (e.type == sf::Event::Closed)
			exit = true;
		//mouse click
		/*
		if (e.type == sf::Event::MouseButtonPressed)
		{
			if (e.mouseButton.button == sf::Mouse::Right)
				Input::r_mouseClicked = true;
			else if (e.mouseButton.button == sf::Mouse::Left)
				Input::l_mouseClicked = true;
		}
		*/
		//mouse release
		/*
		if (e.type == sf::Event::MouseButtonReleased)
		{
			if (e.mouseButton.button == sf::Mouse::Right)
				Input::r_mouseReleased = true;
			else if (e.mouseButton.button == sf::Mouse::Left)
				Input::l_mouseReleased = true;
		}
		*/
	}
}

void BeEngine::updateState(sf::Time dt) 
{
	State* temp = state->update(dt);
	if (temp != nullptr)
	{
		delete state;
		state = temp;
		state->load(this);
	}
}

void BeEngine::render() 
{
	state->render(window);
}

void BeEngine::saveGame() {}

sf::Vector2u BeEngine::getWindowResolution()
{
	return window.getSize();
}

sf::Vector2i BeEngine::getMousePosition(bool relativeToWindow)
{
	if (relativeToWindow)
		return sf::Mouse::getPosition(window);
	else
		return sf::Mouse::getPosition();
}

sf::RenderWindow& BeEngine::getWindow()
{
	return window;
}