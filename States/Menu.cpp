#include "Menu.h"

Menu::Menu() {};

Menu::~Menu() {};

State* Menu::update(sf::Time dt)
{ 
	return nullptr;
};

void Menu::render(sf::RenderWindow& window)
{
	window.clear(sf::Color{255,255,255});
	window.display();
}

std::string Menu::name()
{
	return "Menu";
}

void Menu::load(BeEngine*)
{
}

void Menu::mouseEvent(sf::Event::EventType type, sf::Mouse::Button button, sf::Vector2i position)
{
}