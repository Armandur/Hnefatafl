/*!
 * \file Board.hpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Declaration of Board class
 */

#include <string>
#include <vector>

#include "Printable.hpp"
#include "Tile.hpp"

/*!
 * \class Board
 *
 * \brief Defines a board for Hnefatafl
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Board : public Printable
{
	public:
		//! Different types of boards
		enum Type{HNEFATAFL, ALEA, TABLUT};

		/*!
		 * \brief Default Board constructor
		 *
		 * Initialises board object with type of Board::Type::HNEFATAFL and
		 * adds tiles to the tiles vector. Board will be 11x11. Loads
		 * starting positions from startingPos/hnefatafl.txt and adds 
		 * pieces.
		 */
		Board(void);

		//! Copy Board constructor
		Board(const Board& src);

		/*!
		 * \brief Board constructor with setting of boardtype
		 *
		 * Initialises board object with type of Board::Type and loads
		 * corresponding starting positions and adds tiles and pieces.
		 */
		Board(const Board::Type type = Board::Type::HNEFATAFL);

		//! Board destructor
		~Board(void);

		/*!
		 * \brief Board assignment operator
		 * \param[in] rhs Source to copy from
		 */
		Board& Board::operator=(const Board& rhs);

		/*!
		 * \brief Returns a pointer to the tile at position pos
		 * \param[in] pos Position to tile on board.
		 * \return Returns a pointer to the tile at given position. If
		 * pos is less than 0 or greater than Board.size() function returns
		 * nullptr.
		 */
		Tile* getTile(sf::Vector2<int> pos);
		
		//! Resets the board according to Board::Type _type.
		void resetBoard();

		/*!
		 * \brief Loads piece positions based on current type.
		 */
		void loadBoard();

		/*!
		 * \brief Loads piece positions from file path
		 *
		 * \param[in] path File to load positions from.
		 */
		void loadBoard(const std::string& path);


		/*!
		 * \brief Saves piece positions to file path
		 *
		 * \param[in] path File to save positions to.
		 */
		void saveBoard(const std::string& path);

		/*!
		 * \brief Sets the type of the board
		 * \param[in] type The type of the board
		 */
		void type(const Board::Type& type);

		/*!
		 * \brief Gets the type of the board
		 * \return Returns the type of the board
		 */
		const Board::Type& type() const;

		/*!
		 * \brief Gets information about the current piece
		 * \return Returns the type and position of the piece in a human
		 * readable format.
		 */
		std::string toString();

		//! Returns the boards size.
		const int& size() const;

	private:
		//! Holds pointers to board tiles.
		std::vector<std::vector<Tile*>> tiles;

		//! Holds the boards current type.
		Board::Type _type;

		//! Holds the boards size;
		int _size;
};