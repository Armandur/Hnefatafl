/*!
 * \file Tile.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 *  Declaration of Tile class
 */

#ifndef TILE_H
#define TILE_H

#include <SFML/System.hpp>
#include "BoardEntity.hpp"
#include "Printable.hpp"
#include "Serializable.hpp"

/*!
 * \class Tile
 *
 * \brief Describes a tile on the gameboard
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Tile :  public BoardEntity, public Printable, public Serializable
{
	public:
		//! Different types of Tiles
		enum Type{EMPTY, CORNER, THRONE};

		/*!
		 * \brief Default Tile Constructor
		 * Initialises tile object with Tile::Type::EMPTY and position -1, -1
		 */
		Tile(void);

		/*!
		 * \brief Tile copy constructor
		 * \param[in] src Source to copy from
		 */
		Tile(const Tile& src);

		/*!
		 * \brief Tile constructor with position and type
		 *
		 * Initializes tile object with the position pos and default
		 * type of Tile::Type::EMPTY.
		 *
		 * \param[in] pos The position to set the tile to.
		 * \param[in] type The type to set the tile to. Default is Tile::Type::EMPTY.
		 */
		Tile(const sf::Vector2<int>& pos,
			 const Tile::Type& type = Tile::Type::EMPTY);

		//! Tile Destructor
		~Tile();
		
		/*!
		 * \brief Tile assignment operator
		 * \param[in] rhs Source to copy from
		 */
		Tile& operator=(const Tile& rhs);

		/*!
		 * \brief Set the type of the tile
		 * \param[in] type The Tile::Type to set.
		 */
		void type(const Tile::Type& type);

		/*!
		 * \brief Get the type of the tile
		 * \return Returns the type of the tile.
		 */
		const Tile::Type& type() const;

		/*!
		 * \brief Gets information about the current tile
		 * \return Returns the type and position of the tile in a human
		 * readable format.
		 */
		std::string toString();

		/*!
		 * \brief Serialize the object to JSON
		 */
		void serialize(Json::Value& root);

		/*!
		 * \brief Deserialize the object
		 */
		void deSerialize(Json::Value& root);

	private:

		/*! Initializing function
		 * \note Should be run in every constructor!
		 */
		void _init();

		//! Stores the current Tile::Type.
		Tile::Type _type;
};

#endif