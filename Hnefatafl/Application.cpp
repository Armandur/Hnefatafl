#include <iostream>
#include "Piece.h"


int main()
{
	std::cout << "Hello World!" << std::endl;

	Piece a(sf::Vector2<int>(0, 0), Piece::Type::KING);

	std::cout << a.toString() << std::endl;

	std::cin.get();

	return 0;
}