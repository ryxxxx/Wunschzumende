#pragma once
#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

class BeEngine;

class State
{
public:
	State() {};
	virtual ~State() {};
	virtual State* update(sf::Time) = 0;
	virtual void render(sf::RenderWindow&) = 0;
	virtual std::string name() = 0;
	virtual void load(BeEngine*) = 0;
	virtual void mouseEvent(sf::Event::EventType type, sf::Mouse::Button, sf::Vector2i position) = 0;
protected:
	entt::registry registry;
};