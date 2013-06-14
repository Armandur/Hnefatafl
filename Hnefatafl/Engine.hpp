/*!
 * \file Engine.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of Engine class
 */
#ifndef ENGINE_H
#define ENGINE_H

#include <stack>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class State;

/*!
 * \class Engine
 *
 * \brief Game engine with state machine, logic- and event handling
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Engine
{
	public:
		//! Initialises window and starts engine
		void init(const std::string& title, const sf::Vector2<int> dimensions);

		//! Performs cleanup at end of life
		void cleanUp();

		//! Change the current state
		void changeState(State* state);

		//! Push another state to the state machine, pausing the current one
		void pushState(State* state);

		//! Resume a state after another one has been pushed on top
		void popState();

		//! Handle events
		void handleEvents();

		//! Update engine
		void update();

		//! Draw stuff
		void draw();

		//! \return Returns true if the engine is running
		const bool& running() const { return _running; }

		//! Exit the engine
		void quit(){ _running = false; window->close();}

		//! Pointer to the current SFML RenderWindow
		sf::RenderWindow* window;

	private:

		//! Holds the engine states
		std::stack<State*> states;

		//! Stores whether the engine is running
		bool _running;
};

#endif