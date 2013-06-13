/*!
 * \file Tile.cpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Definition of the Tile class-
 */

#include <sstream>

#include "Tile.hpp"


Tile::Tile(void)
{
	_init();
	this->position(sf::Vector2<int>(-1, -1));
	this->type(Tile::Type::EMPTY);
}

Tile::Tile(const Tile& src)
{
	_init();
	this->position(src.position());
	this->type(src.type());
}

Tile::Tile(const sf::Vector2<int>& pos, const Tile::Type& type/*=Tile::Type::EMPTY*/)
{
	_init();
	this->position(pos);
	this->type(type);
}


Tile::~Tile(void)
{

}

void Tile::type(constTile::Type& type)
{
	this->_type = type;
}

const Tile::Type& Tile::type() const
{
	return this->_type;
}

std::string Tile::toString()
{
	std::stringstream ss;

	ss << "Tile" << std::endl
		<< "\tPosition (x, y):\t(" << _position.x << ", " << _position.y << ')' << std::endl
		<< "\tType:\t";

	switch(_type)
	{
		case EMPTY :
				ss << "Empty";
			break;
		case CORNER :
				ss << "Corner";
			break;
		case THRONE :
				ss << "Throne";
			break;
		default:
				ss << "Undefined";
			break;
	}

	ss << std::endl;

	return ss.str();
}

void Tile::_init()
{

}