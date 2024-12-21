// knight.cpp
#include "piece.h"
#include "knight.h"

namespace chess {
	
	Knight::Knight(std::string pieceColor, std::pair<int, int> currSquare)
		: Piece("knight", pieceColor, currSquare) {};

	bool Knight::isValidMove(std::pair<int, int> destSquare) const {
		if (isValidSquare(destSquare)) {
			// FIXME:
		}
		return false;
	};
}