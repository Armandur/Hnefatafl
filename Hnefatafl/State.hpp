/*!
 * \file State.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of Abstract State class
 */

#ifndef  STATE_H
#define STATE_H

#include "Engine.hpp"

/*!
 * \class State
 *
 * \brief Abstract baseclass for a state for use in the game engine
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class State
{
	public:
		//! Initalises state
		virtual void init() =0;

		//! Performs cleanUp at end of state
		virtual void cleanUp() =0;

		//! Pauses state
		virtual void pause() =0;

		//! Resumes state
		virtual void resume() =0;

		//! Handle events
		virtual void handleEvents(Engine* game) =0;

		//! Update state
		virtual void update(Engine* game) =0;

		//! Draw graphics
		virtual void draw(Engine* game) =0;

		//! Change the state
		void changeState(Engine* game, State* state)
		{
			game->changeState(state);
		}

	protected:
		State(void){}
};

#endif