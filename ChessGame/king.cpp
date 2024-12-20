// king.cpp
#include "king.h"
#include <cmath>

namespace chess {
	
	King::King( std::string pieceColor, std::pair<int, int> currSquare)
		: Piece("king", pieceColor, currSquare) {};

	bool King::isValidMove(std::pair<int, int> destSquare) const {
		int xTravel;
		int yTravel;

		if (isValidSquare(destSquare)) {
			xTravel = abs(destSquare.first - currSquare.first);
			yTravel = abs(destSquare.second - currSquare.second);

			// FIXME: can simplify this I'm sure...
			return ((xTravel == 1) && (yTravel == 0))
				|| ((yTravel == 1) && (xTravel == 0))
				|| ((xTravel == 1) && (yTravel == 1));
		}
		return false;
	};
}