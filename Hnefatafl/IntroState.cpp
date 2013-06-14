/*!
 * \file IntroState.cpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Definition of IntroState class
 */

#include <iostream>

#include "IntroState.hpp"

void IntroState::init()
{
	if(!font.loadFromFile("data/fonts/arial.ttf"))
	{
		std::cerr << "IntroState::draw : could not load font" << std::endl;
	}

	introText.setFont(font);
	introText.setString("An Armandur Games Production");
	introText.setCharacterSize(50);
	introText.setColor(sf::Color::Black);

	sf::Vector2f introTextMid;
	introTextMid.x = introText.getLocalBounds().width / 2;
	introTextMid.y = introText.getLocalBounds().height / 2;

	introText.setOrigin(introTextMid);
	introText.setPosition(400, 300);
}

void IntroState::cleanUp()
{

}

void IntroState::pause()
{

}

void IntroState::resume()
{

}

void IntroState::handleEvents(Engine* game)
{
	sf::Event event;

	while(game->window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			game->quit();
		}
		else
		{
			//game->changeState(MenuState::instance());
		}
	}
}

void IntroState::update(Engine* game)
{
	
}

void IntroState::draw(Engine* game)
{
	game->window->clear(sf::Color::White);
	game->window->draw(introText);
}

IntroState IntroState::_IntroState;