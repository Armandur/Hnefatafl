/*!
 * \file Engine.cpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Definition of game engine with state machine
 */

#include "Engine.hpp"
#include "State.hpp"

void Engine::init(const std::string& title, const sf::Vector2<int> dimensions)
{
	window = new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), title);
	
	window->setFramerateLimit(30);
	window->setVerticalSyncEnabled(true);

	_running = true;
}

void Engine::cleanUp()
{
	while(!states.empty())
	{
		states.top()->cleanUp();
		states.pop();
	}
}

void Engine::changeState(State* state)
{
	// Cleanup last state
	if(!states.empty())
	{
		states.top()->cleanUp();
		states.pop();
	}

	//New state
	states.push(state);
	states.top()->init();
}

void Engine::pushState(State* state)
{
	//Pause last state, if any
	if(!states.empty())
	{
		states.top()->pause();
	}

	states.push(state);
	states.top()->init();
}

void Engine::popState()
{
	//Remove pushed state
	if (!states.empty())
	{
		states.top()->cleanUp();
		states.pop();
	}

	//Resume last state
	if (!states.empty())
	{
		states.top()->resume();
	}
}

void Engine::handleEvents()
{
	//Tell the current state to handle events
	states.top()->handleEvents(this);
}

void Engine::update()
{
	//Update the current sate
	states.top()->update(this);
}

void Engine::draw()
{
	window->clear();

	//Tell the state to draw its current graphics
	states.top()->draw(this);

	window->display();
}