#include <iostream>
#include "Tile.hpp"
#include "Piece.hpp"
#include "Serializer.hpp"

int main()
{
	std::cout << "Hello World!" << std::endl;

	Piece b(sf::Vector2<int>(2, 5));
	Tile a(sf::Vector2<int>(0, 0));

	std::string _a, _b;

	Serializer::serialize(&a, _a);
	Serializer::serialize(&b, _b);


	std::cout << _b << std::endl;

	Piece c;

	Serializer::deSerialize(&c, _b);

	std::cout << c.toString() << std::endl;

	std::cin.get();

	return 0;
}