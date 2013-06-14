#include <iostream>
#include <thread>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Engine.hpp"
#include "IntroState.hpp"

int main()
{
	Engine engine;

	engine.init("Hnefatafl", sf::Vector2<int>(800, 600));

	engine.pushState(IntroState::instance());

	while(engine.running())
	{
		engine.handleEvents();
		engine.update();
		engine.draw();
	}

	engine.cleanUp();
	return 0;
}