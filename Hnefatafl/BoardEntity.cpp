/*!
 * \file BoardEntity.cpp
 *
 * \author Rasmus Pettersson Vik
 * \date juni 2013
 *
 * Definition of the abstract baseclass BoardEntity
 */

#include "BoardEntity.hpp"

BoardEntity::BoardEntity(void)
{
	this->_init();
	this->position(sf::Vector2<int>(-1, -1));
}


BoardEntity::~BoardEntity(void)
{

}


void BoardEntity::position(const sf::Vector2<int>& pos)
{
	this->_position = pos;
}

const sf::Vector2<int>& BoardEntity::position() const
{
	return _position;
}

void BoardEntity::_init()
{

}