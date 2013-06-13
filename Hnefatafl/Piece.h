#ifndef PIECE_H
#define PIECE_H

#include <SFML/System.hpp>

class Piece
{
	public:
		enum Type {BLACK, WHITE, KING};

		Piece();
		Piece(const Piece& org);
		Piece(const sf::Vector2<int> pos, Piece::Type type = Type::BLACK);
		~Piece();

		Piece::Type type() const;
		void type(const Piece::Type&);

		sf::Vector2<int> position() const;
		void position(const sf::Vector2<int> pos);

		std::string toString() const;

	private:
		Piece::Type _type;
		sf::Vector2<int> _position;
};

#endif