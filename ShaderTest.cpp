#include "ShaderTest.h"
#include "BeEngine.h"
#include <Windows.h>
#include <Uxtheme.h>
#include <dwmapi.h>
#pragma comment (lib, "dwmapi.lib")

ShaderTest::ShaderTest() {};

ShaderTest::~ShaderTest() {};

State* ShaderTest::update(sf::Time dt)
{
	shader.setUniform("time", clock.getElapsedTime().asSeconds());
	auto mouse = static_cast<sf::Vector2f>(engine->getMousePosition());
	auto res = static_cast<sf::Vector2f>(engine->getWindowResolution());
	shader.setUniform("mouse", sf::Vector2f{ mouse.x / res.x,mouse.y / res.y });
	return nullptr;
};

void ShaderTest::render(sf::RenderWindow& window)
{
	window.clear(sf::Color{ 0,0,0,0 });
	window.draw(spr, &shader);
	window.display();
}

std::string ShaderTest::name()
{
	return "ShaderTest";
}

void ShaderTest::load(BeEngine* _engine)
{
	engine = _engine;
	tex.loadFromFile("imgShaderTest.png");
	spr.setTexture(tex);
	shader.loadFromFile("shaderTest.frag", sf::Shader::Fragment);
	shader.setUniform("resolution", static_cast<sf::Vector2f>(engine->getWindowResolution()));
	shader.setUniform("sourceTexture", sf::Shader::CurrentTexture);

	HWND handle = engine->getWindow().getSystemHandle();

	//Fenster immer an oberster Stelle:
	SetWindowPos(handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	//Fenster Transparent:
	MARGINS margins;
	margins.cxLeftWidth = -1;
	SetWindowLong(handle, GWL_STYLE, WS_POPUP | WS_VISIBLE);
	DwmExtendFrameIntoClientArea(handle, &margins);
}