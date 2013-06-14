#include <vector>
#include <sstream>
#include <fstream>
#include <json/json.h>

#include "Board.hpp"

#include "Tile.hpp"
#include "Piece.hpp"
#include "Serializer.hpp"

Board::Board(const Board::Type type/*=Board::Type::HNEFATAFL*/)
{
	this->type(type);

	/*! Different types of boards
	*	ARD, BRANDUB = 7x7;
	*	TABLUT = 9x9;
	*	TAWLBYUND, HNEFATAFL = 11x11;
	*	ALEA = 19x19
	*/
	switch(this->type())
	{
		case ARD :
		case BRANDUB :
				this->_size = 7;
			break;
		case TABLUT :
				this->_size = 9;
			break;
		case TAWLBYUND :
		case HNEFATAFL :
				this->_size = 11;
			break;
		case ALEA :
				this->_size = 19;
			break;
		default:
				this->_size = -1;
			break;
	}

	this->loadBoardLayout();
}

Board::Board(const Board& src)
{
	this->type(src.type());
	this->_size = src.size();

	tiles.resize(src.tiles.size());
	for(int i = 0; i < src.tiles.size(); i++)
	{
		std::vector<Tile*> row;

		for(int j = 0; j < src.tiles[i].size(); j++)
		{
			row.push_back(new Tile((*src.tiles[i][j])));
		}

		tiles.push_back(row);
	}
}

Board::~Board(void)
{

}

Board& Board::operator=(const Board& rhs)
{
	tiles.resize(rhs.tiles.size());
	for(int i = 0; i <  rhs.tiles.size(); i++)
	{
		std::vector<Tile*> row;

		for(int j = 0; j < rhs.tiles[i].size(); j++)
		{
			row.push_back(new Tile((*rhs.tiles[i][j])));
		}

		tiles.push_back(row);
	}

	return *this;
}

Tile* Board::getTile(sf::Vector2<int> pos)
{
	if(pos.x < 0 || pos.y < 0 || pos.x > this->size() || pos.y > this->size())
	{
		return nullptr;
	}

	for(auto i = tiles.begin(); i != tiles.end(); i++)
	{
		for(auto j = i->begin(); j != i->end(); j++)
		{
			if((*j)->position() == pos)
			{
				return (*j);
			}
		}
	}

	return nullptr;
}

Piece* Board::getPiece(sf::Vector2<int> pos)
{
	if(pos.x < 0 || pos.y < 0 || pos.x > this->size() || pos.y > this->size())
	{
		return nullptr;
	}

	for(auto it = pieces.begin(); it != pieces.end(); it++)
	{
		if((*it)->position() == pos)
		{
			return (*it);
		}
	}

	return nullptr;
}

void Board::resetBoard()
{
	
}

void Board::loadBoardLayout()
{
	std::string paths[6] = {
							"ard.txt",
							"brandub.txt",
							"tablut.txt",
							"tawlbyund.txt",
							"hnefatafl.txt",
							"alea.txt"
						  };

	this->loadBoardLayout("data/boardLayout/"+paths[type()]);
}

void Board::loadBoardLayout(const std::string& path)
{
	
}

void Board::loadPieces(const std::string& path)
{
	std::ifstream file(path);

	std::string root((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void Board::saveCurrentBoard(const std::string& path)
{
	std::ofstream file;
	file.open(path);
}

void Board::type(const Board::Type& type)
{
	this->_type = type;
}

const Board::Type& Board::type() const
{
	return this->_type;
}

std::string Board::toString()
{
	std::stringstream ss;

	ss << "temp" << std::endl;

	return ss.str();
}

const int& Board::size() const
{
	return this->_size;
}

void Board::serialize(Json::Value& root)
{
	
}

void Board::deSerialize(Json::Value& root)
{
	
}