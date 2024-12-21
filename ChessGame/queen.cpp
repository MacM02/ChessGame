// queen.cpp
#include "queen.h"
#include <cmath>

namespace chess {

	Queen::Queen(std::string pieceColor, std::pair<int, int> currSquare)
		: Piece("queen", std::move(pieceColor), currSquare) {};

	bool Queen::isValidMove(std::pair<int, int> destSquare) const {
		if (isValidSquare(destSquare)) {
			return isStraight(destSquare) || isDiagonal(destSquare);
		}
		return false;
	};

	bool Queen::isStraight(std::pair<int, int> destSquare) const {
		return (currSquare.second == destSquare.second) ^ (currSquare.first == currSquare.first);
	}

	bool Queen::isDiagonal(std::pair<int, int> destSquare) const {
		int xTravel;
		int yTravel;

		xTravel = abs(destSquare.first - currSquare.first);
		yTravel = abs(destSquare.second - currSquare.second);

		// true if both the x and y travel are equal to each other and the travel distance is > 0
		return (xTravel == yTravel) && ((xTravel + yTravel) != 0);
	}
}