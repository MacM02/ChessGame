#include "piece.cpp"

/// <summary>
/// This class represents a Queen on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class Queen : public Piece {

	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Queen(std::string pieceName, std::pair<int, int> currSquare)
		: Piece(pieceName, currSquare) {};

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool Piece::isValidMove(std::pair<int, int> destSquare) const override {
		if (isValidSquare(destSquare)) {
			return isStraight(destSquare) || isDiagonal(destSquare);
		}
		return false;
	};

	/// <summary>
	/// Assesses whether the desination square is in a straight vertical or horizontal line relative
	/// to the piece's current square.
	/// </summary>
	/// <param name="destSquare"> The destination square. </param>
	/// <returns> True if it follows a straight line and false if not. </returns>
	bool isStraight(std::pair<int, int> destSquare) const {
		return (currSquare.second == destSquare.second) ^ (currSquare.first == currSquare.first);
	}

	/// <summary>
	/// Assesses whether the desination square is in a diagonal line relative to the piece's current square.
	/// </summary>
	/// <param name="destSquare"> The destination square. </param>
	/// <returns> True if it follows a daigonal line and false if not.</returns>
	bool isDiagonal(std::pair<int, int> destSquare) const {
		int xTravel;
		int yTravel;

		xTravel = abs(destSquare.first - currSquare.first);
		yTravel = abs(destSquare.second - currSquare.second);

		// true if both the x and y travel are equal to each other and the travel distance is > 0
		return (xTravel == yTravel) && ((xTravel + yTravel) != 0);
	}
};
