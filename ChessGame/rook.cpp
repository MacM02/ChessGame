// rook.cpp
#include "rook.h"

namespace chess {
	
	// Rook constructor 
	Rook::Rook(std::string pieceColor, std::pair<int, int> currSquare)
		: Piece("rook", pieceColor, currSquare) {};

	// checks whether the destination square is valid for this piece
	bool Rook::isValidMove(std::pair<int, int> destSquare) const {
		if (isValidSquare(destSquare)) {

			// returns true if exactly 1 on the conditions is true and false otherwise
			return (currSquare.second == destSquare.second) ^ (currSquare.first == currSquare.first);
		}
		return false;
	};
}