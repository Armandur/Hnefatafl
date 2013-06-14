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
#include <list>

#include <SFML/System.hpp>

#include "Printable.hpp"
#include "Serializable.hpp"

class Tile;
class Piece;

/*!
 * \class Board
 *
 * \brief Defines a board for Hnefatafl
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 */
class Board : public Printable, public Serializable
{
	public:
		/*! Different types of boards
		 *	ARD, BRANDUB = 7x7;
		 *	TABLUT = 9x9;
		 *	TAWLBYUND, HNEFATAFL = 11x11;
		 *	ALEA = 19x19
		 */
		enum Type{ARD, BRANDUB, TABLUT, TAWLBYUND, HNEFATAFL, ALEA};

		/*!
		 * \brief Board constructor with setting of boardtype
		 *
		 * Initialises board object with type of Board::Type and loads
		 * corresponding starting positions and adds tiles and pieces.
		 */
		Board(const Board::Type type = Board::Type::HNEFATAFL);

		//! Copy Board constructor
		Board(const Board& src);

		//! Board destructor
		~Board(void);

		/*!
		 * \brief Board assignment operator
		 * \param[in] rhs Source to copy from
		 */
		Board& operator=(const Board& rhs);

		/*!
		 * \brief Returns a pointer to the tile at position pos
		 * \param[in] pos Position to tile on board.
		 * \return Returns a pointer to the tile at given position. If
		 * pos is less than 0 or greater than Board.size() function returns
		 * nullptr.
		 */
		Tile* getTile(sf::Vector2<int> pos);

		/*!
		 * \brief Returns a pointer to a piece at position pos
		 * \param[in] pos Position to a tile on board.
		 * \return Returns a pointer to a piece at the position. If pos
		 * is out of bounds or if there's no piece at the position it returns
		 * nullptr.
		 */
		Piece* Board::getPiece(sf::Vector2<int> pos);
		
		//! Resets the board according to Board::Type _type.
		void resetBoard();

		/*!
		 * \brief Loads piece positions based on current type.
		 */
		void loadBoardLayout();

		/*!
		 * \brief Loads board layout from file path
		 *
		 * \param[in] path File to load layout from.
		 */
		void loadBoardLayout(const std::string& path);

		/*!
		 * \brief Loads pieces and positions from file path
		 *
		 * \param[in] path File to load pieces from.
		 */
		void loadPieces(const std::string& path);
		
		/*!
		 * \brief Saves current board positions to file path
		 *
		 * \param[in] path File to save positions to.
		 */
		void saveCurrentBoard(const std::string& path);

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

		/*!
		 * \brief Serialize the object to JSON
		 */
		void serialize(Json::Value& root);

		/*!
		 * \brief Deserialize the object
		 */
		void deSerialize(Json::Value& root);

	private:
		//! Holds pointers to board tiles.
		std::vector<std::vector<Tile*>> tiles;

		//! Holds pointers to pieces on the board
		std::list<Piece*> pieces;

		//! Holds the boards current type.
		Board::Type _type;

		//! Holds the boards size;
		int _size;
};