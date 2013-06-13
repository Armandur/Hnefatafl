#include <string>
#include <sstream>

#include "Piece.h"

Piece::Piece()
{
	this->_position.x = this->_position.y = 0;
	this->type(Piece::Type::BLACK);
}

Piece::Piece(const Piece&)
{

}

Piece::Piece(const sf::Vector2<int> pos, Piece::Type type/*=Piece::Type::Black*/)
{
	this->position(pos);
	this->type(type);
}

Piece::~Piece()
{

}

Piece::Type Piece::type() const
{
	return this->_type;
}

void Piece::type(const Piece::Type& type)
{
	this->_type = type;
}

sf::Vector2<int> Piece::position() const
{
	return this->_position;
}

void Piece::position(const sf::Vector2<int> pos)
{
	this->_position = pos;
}

std::string Piece::toString() const
{
	std::stringstream ss;

	ss << "Piece" << std::endl
	   << "\tType:\t";
	switch(_type)
	{
		case BLACK :
				ss << "Black";
			break;

		case WHITE :
				ss << "White";
			break;

		case KING :
				ss << "King";
			break;

		default :
				ss << "NONE";
			break;
	}

	ss << std::endl;

	ss << "\tPosition (x, y):\t(" <<  _position.x << ", " << _position.y << ')' << std::endl;

	return ss.str();
}