#pragma once
#include "State.h"

class Menu : public State
{
public:
	Menu();
	~Menu();
	
	State* update(sf::Time dt);
	void render(sf::RenderWindow& window);
	std::string name();
	void load(BeEngine*);
	void mouseEvent(sf::Event::EventType type, sf::Mouse::Button button, sf::Vector2i position);
};

