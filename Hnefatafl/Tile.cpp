/*!
 * \file Tile.cpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Definition of the Tile class-
 */

#include <sstream>
#include <json/json.h>

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

Tile& Tile::operator=(const Tile& rhs)
{
	this->position(rhs.position());
	this->type(rhs.type());

	return *this;
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

void Tile::serialize(Json::Value& root)
{
	root["posX"] = this->position().x;
	root["posY"] = this->position().y;

	switch(_type)
	{
		case Tile::Type::EMPTY :
				root["type"] = "empty";
			break;
		case Tile::Type::CORNER :
				root["type"] = "corner";
			break;
		case Tile::Type::THRONE :
				root["type"] = "throne";
			break;
		default:
				root["type"] = "undefined";
			break;
	}
}

void Tile::deSerialize(Json::Value& root)
{
	this->position(sf::Vector2<int>(root.get("posX", -1).asInt(), root.get("posY", -1).asInt()));

	std::string type = root.get("type", "").asString();

	if(type == "empty")
	{
		this->type(Tile::Type::EMPTY);
	}
	else if(type == "corner")
	{
		this->type(Tile::Type::CORNER);
	}
	else if(type == "throne")
	{
		this->type(Tile::Type::THRONE);
	}
	else
	{
		this->type(Tile::Type::EMPTY);
	}
}

void Tile::_init()
{

}