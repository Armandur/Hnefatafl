#include <iostream>
#include "Tile.hpp"
#include "Piece.hpp"

int main()
{
	std::cout << "Hello World!" << std::endl;

	Piece b(sf::Vector2<int>(2, 5));
	Tile a(sf::Vector2<int>(0, 0));

	std::cout << a.toString() << b.toString() << std::endl;

	std::cin.get();

	return 0;
}