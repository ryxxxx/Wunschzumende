#include "MovementTest.h"
#include "BeEngine.h"

MovementTest::MovementTest()
{
};

MovementTest::~MovementTest() 
{
};

State* MovementTest::update(sf::Time dt) 
{
	return nullptr;
};

void MovementTest::render(sf::RenderWindow& window) 
{
	window.clear();
	window.draw(sprBackground);
	window.draw(sprPlayer);
	window.display();
};

std::string MovementTest::name() 
{ 
	return "MovementTest"; 
};

void MovementTest::load(BeEngine* e) 
{
	texBackground.loadFromFile("imgBackgroundMovementTest.png");
	sprBackground.setTexture(texBackground);
	texPlayer.loadFromFile("imgPlayer.png");
	sprPlayer.setTexture(texPlayer);
};

void MovementTest::mouseEvent(sf::Event::EventType type, sf::mous sf::Vector2i position)
{
	if(type==sf::Event::MouseButtonReleased)
}