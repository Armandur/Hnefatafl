/*!
 * \file Piece.cpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Definition of Piece class
 */
#include <string>
#include <sstream>

#include "Piece.hpp"

Piece::Piece(void)
{
	_init();
	this->position(sf::Vector2<int>(-1, -1));
	this->type(Piece::Type::BLACK);
}

Piece::Piece(const Piece& src)
{
	_init();
	this->position(src.position());
	this->type(src.type());
}

Piece::Piece(const sf::Vector2<int>& pos, const Piece::Type& type/*=Piece::Type::BLACK*/)
{
	_init();
	this->position(pos);
	this->type(type);
}

Piece::~Piece(void)
{

}

Piece& Piece::operator=(const Piece& rhs)
{
	this->position(rhs.position());
	this->type(rhs.type());

	return *this;
}

void Piece::type(constPiece::Type& type)
{
	this->_type = type;
}

const Piece::Type& Piece::type() const
{
	return this->_type;
}

std::string Piece::toString()
{
	std::stringstream ss;

	ss << "Piece" << std::endl
		<< "\tPosition (x, y):\t(" << _position.x << ", " << _position.y << ')' << std::endl
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
		default:
				ss << "Undefined";
			break;
	}

	ss << std::endl;

	return ss.str();
}

void Piece::_init()
{

}