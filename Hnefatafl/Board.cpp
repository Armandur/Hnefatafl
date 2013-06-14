#include <vector>
#include <sstream>
#include <fstream>

#include "Board.hpp"
#include "Tile.hpp"

Board::Board(void)
{
	this->type(Board::Type::HNEFATAFL);
	this->loadBoard();
}

Board::Board(const Board& src)
{
	tiles.resize(src.tiles.size());
	for(int i = 0; i < src.size(); i++)
	{
		std::vector<Tile*> row;

		for(int j = 0; j < src.tiles[i].size(); j++)
		{
			row.push_back(new Tile((*src.tiles[i][j])));
		}

		tiles.push_back(row);
	}
}

Board::Board(const Board::Type type/*=Board::Type::HNEFATAFL*/)
{
	this->type(type);
	this->loadBoard();
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

void Board::resetBoard()
{
	
}

void Board::loadBoard()
{

}

void Board::loadBoard(const std::string& path)
{

}

void Board::saveBoard(const std::string& path)
{

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