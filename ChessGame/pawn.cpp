#pragma once
#include "pawn.h"

namespace chess {

	Pawn::Pawn(std::string pieceColor, std::pair<int, int> currSquare)
		: Piece("pawn", std::move(pieceColor), currSquare) {};

	bool Pawn::isValidMove(std::pair<int, int> destSquare) const {

		int xTravel;
		int yTravel;

		if (isValidSquare(destSquare)) {
			xTravel = destSquare.first - currSquare.first;
			yTravel = destSquare.second - currSquare.second;

			// if the pawn is white and on its starting square
			if (this->color == "white" && this->currSquare.first == 1) {
				return (xTravel == 1) && (yTravel == 0)
					|| (xTravel == 2) && (yTravel == 0)
					|| ((xTravel == yTravel) && ((xTravel == 1) && (abs(yTravel) == 1)));
			}

			// if pawn is white and has moved this game
			else if (this->color == "white") {
				return (xTravel == 1) && (yTravel == 0)
					|| ((xTravel == yTravel) && ((xTravel == 1) && (abs(yTravel) == 1)));
			}

			// if the pawn is black and on its starting square
			if (this->color == "black" && this->currSquare.first == 6) {
				return (xTravel == -1) && (yTravel == 0)
					|| (xTravel == -2) && (yTravel == 0)
					|| ((xTravel == yTravel) && ((xTravel == -1) && (abs(yTravel) == 1)));
			}

			// if pawn is black and has moved this game
			else if (this->color == "black") {
				return (xTravel == -1) && (yTravel == 0)
					|| ((xTravel == yTravel) && ((xTravel == -1) && (abs(yTravel) == 1)));
			}
		}
		return false;
	};
}