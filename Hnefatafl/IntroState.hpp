/*!
 * \file IntroState.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of Intro Gamestate
 */
#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "State.hpp"

/*!
 * \class IntroState
 *
 * \brief Introductory state when starting the game
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class IntroState : public State
{
	public:
		//! Initalises state, loads fonts and sets text etc.
		void init();

		//! CleanUp
		void cleanUp();
		
		//! Pause state
		void pause();

		//! Resume state
		void resume();

		//! Handle events from SFML during current state
		void handleEvents(Engine* game);

		//! Update
		void update(Engine* game);

		//! Draw stuff
		void draw(Engine* game);

		//! Static instance to this state
		static IntroState* instance()
		{
			return &_IntroState;
		}

	protected:
		IntroState(void){}

		sf::Text introText;
		sf::Font font;

	private:
		static IntroState _IntroState;
};

#endif