#include "piece.cpp"

/// <summary>
/// This class represents a King on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class King : public Piece {
	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	King(std::string pieceName, std::pair<int, int> currSquare)
		: Piece(pieceName, currSquare) {};

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool Piece::isValidMove(std::pair<int, int> destSquare) const override {
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
};
