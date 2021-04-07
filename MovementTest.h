#pragma once
#include "State.h"
class MovementTest : public State
{
public:
	MovementTest();
	~MovementTest();

	State* update(sf::Time dt);
	void render(sf::RenderWindow& window);
	std::string name();
	void load(BeEngine*);
	void mouseEvent(sf::Event::EventType type, sf::Vector2i position);
private:
	sf::Texture texBackground, texPlayer;
	sf::Sprite sprBackground, sprPlayer;
	sf::Shader vertPlayer;
	sf::Vector2f acceleration, velocity;
};

