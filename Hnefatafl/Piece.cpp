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

void Piece::serialize(Json::Value& root)
{
	root["posX"] = this->position().x;
	root["posY"] = this->position().y;
	
	switch(_type)
	{
		case Piece::Type::BLACK :
				root["type"] = "black";
			break;
		case Piece::Type::WHITE :
				root["type"] = "white";
			break;
		case Piece::Type::KING :
				root["type"] = "king";
			break;
		default:
				root["type"] = "undefined";
			break;
	}
}

void Piece::deSerialize(Json::Value& root)
{
	this->position(sf::Vector2<int>(root.get("posX", -1).asInt(), root.get("posY", -1).asInt()));

	std::string type = root.get("type", "").asString();

	if(type == "black")
	{
		this->type(Piece::Type::BLACK);
	}
	else if(type == "white")
	{
		this->type(Piece::Type::WHITE);
	}
	else if(type == "king")
	{
		this->type(Piece::Type::KING);
	}
	else
	{
		this->type(Piece::Type::BLACK);
	}
}

void Piece::_init()
{

}
