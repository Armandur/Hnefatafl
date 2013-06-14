/*!
 * \file BoardEntity.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 *  Declaration of the abstract baseclass BoardEntity
 */

#ifndef BOARDENTITY_H
#define BOARDENTITY_H

#include <SFML/System.hpp>

/*!
 * \class BoardEntity
 *
 * \brief  Abstract baseclass for an entity with a position on the gameboard.
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class BoardEntity
{
	public:

		/*!
		 * \brief Default BoardEntity Constructor
		 * Runs _init() and initialises _position to (-1, -1)
		 */
		BoardEntity(void);

		//! Virtual BoardEntity destructor
		virtual ~BoardEntity(void);

		/*!
		 * \brief Sets the position of the BoardEntity
		 * \param[in] pos The position to set.
		 */
		void position(const sf::Vector2<int>& pos);

		/*!
		 * \brief Gets the position of the BoardEntity
		 * \return Gets the position of the BoardEntity.
		 */
		const sf::Vector2<int>& position() const;

	protected:
		/*! Initializing function
		 * \note Should be run in every constructor!
		 */
		virtual void _init() =0;

		//! Holds the current position of the BoardEntity
		sf::Vector2<int> _position;
};

#endif