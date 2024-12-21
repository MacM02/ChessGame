// bishop.cpp
#include "bishop.h"
#include <cmath>

namespace chess {
	
	// constructor for the Bishop
	Bishop::Bishop(std::string pieceColor, std::pair<int, int> currSquare)
		: Piece("bishop", std::move(pieceColor), currSquare) {};

	// checks whether the bishop's move is valid
	bool Bishop::isValidMove(std::pair<int, int> destSquare) const {
		int xTravel;
		int yTravel;

		if (isValidSquare(destSquare)) {
			xTravel = abs(destSquare.first - currSquare.first);
			yTravel = abs(destSquare.second - currSquare.second);

			// true if both the x and y travel are equal to each other and the travel distance is > 0
			return (xTravel == yTravel) && ((xTravel + yTravel) != 0);
		}
		return false;
	};
}