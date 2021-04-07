#pragma once
#include "State.h"

class ShaderTest : public State
{
public:
	ShaderTest();
	~ShaderTest();

	State* update(sf::Time dt);
	void render(sf::RenderWindow& window);
	std::string name();
	void load(BeEngine*);
private:
	sf::Texture tex;
	sf::Sprite spr;
	sf::Shader shader;
	sf::Clock clock;
	BeEngine* engine;
};

