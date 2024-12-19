#include "piece.cpp"
#include <cmath>

/// <summary>
/// This class represents a Bishop on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class Bishop : public Piece {
	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Bishop(std::string pieceName, std::pair<int, int> currSquare)
		: Piece(pieceName, currSquare) {};

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool Piece::isValidMove(std::pair<int, int> destSquare) const override {
		if ((destSquare.first > 7 || destSquare.first < 0) || (destSquare.second > 7 || destSquare.second < 0)) {
			return false;
		}

		int xTravel = abs(destSquare.first - currSquare.first);
		int yTravel = abs(destSquare.second - currSquare.second);

		// not valid if the bishop has not moved at all
		if (xTravel == 0 && yTravel == 0) {
			return false;
		}

		// true if both the x and y travel are equal to each other, creating a diagonal line
		return xTravel == yTravel;
	};
};
