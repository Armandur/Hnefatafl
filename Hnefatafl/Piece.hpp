/*!
 * \file Piece.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of Piece class
 */
#ifndef PIECE_H
#define PIECE_H

#include <SFML/System.hpp>
#include "BoardEntity.hpp"
#include "Printable.hpp"

/*!
 * \class Piece
 *
 * \brief Describes a piece on the gameboard
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Piece : protected BoardEntity, protected Printable
{
	public:
		//! Different types of Pieces
		enum Type{BLACK, WHITE, KING};

		/*!
		 * \brief Default Piece Constructor
		 * Initialises tile object with Piece::Type::Black and position -1, -1
		 */
		Piece(void);

		/*!
		 * \brief Piece copy constructor
		 * \param[in] src Source to copy from
		 */
		Piece(const Piece& src);

		/*!
		 * \brief Piece constructor with position and type
		 *
		 * Initialises tile object with the position pos and default
		 * type of Piece::Type::BLACK.
		 *
		 * \param[in] pos The position to set the piece to.
		 * \param[in] type The type to set the piece to. Default is Piece::Type::BLACK.
		 */
		Piece(const sf::Vector2<int>& pos,
			 const Piece::Type& type = Piece::Type::BLACK);

		//! Piece destructor
		~Piece(void);

		/*!
		 * \brief Sets the type of the piece
		 * \param[in] type The type of the piece
		 */
		void type(const Piece::Type& type);

		/*!
		 * \brief Gets the type of the piece
		 * \return Returns the type of the piece
		 */
		const Piece::Type& type() const;

		/*!
		 * \brief Gets information about the current piece
		 * \return Returns the type and position of the piece in a human
		 * readable format.
		 */
		std::string toString();
	
	private:
		/*! Initialising function
		 * \note Should be run in every constructor!
		 */
		void _init();

		//! Stores the current Piece::Type.
		Piece::Type _type;
};

#endif