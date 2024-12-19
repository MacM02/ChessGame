#pragma once
#include "piece.cpp"
#include <cmath>

/// <summary>
/// This class represents a Bishop on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class Bishop : public Piece {
public:
	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Bishop(std::string pieceName, std::string pieceColor, std::pair<int, int> currSquare)
		: Piece(pieceName, pieceColor, currSquare) {};

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

			// true if both the x and y travel are equal to each other and the travel distance is > 0
			return (xTravel == yTravel) && ((xTravel + yTravel) != 0);
		}
	};
};
