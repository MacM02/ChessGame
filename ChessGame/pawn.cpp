#pragma once
#include "piece.cpp"

/// <summary>
/// This class represents a Pawn on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class Pawn : public Piece {

	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Pawn(std::string pieceName, std::string pieceColor, std::pair<int, int> currSquare)
		: Piece(pieceName, pieceColor, currSquare) {};

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool Piece::isValidMove(std::pair<int, int> destSquare) const override {

		int xTravel;
		int yTravel;

		if (isValidSquare(destSquare)) {
			xTravel = destSquare.first - currSquare.first;
			yTravel = destSquare.second - destSquare.second;

			// if the pawn is white
			if (this->color == "white" && this->currSquare.first == 1) {
				return (xTravel == 1) && (yTravel == 0)
					|| (xTravel == 2) && (yTravel == 0);
			}
			else if (this->color == "white") {
				return (xTravel == 1) && (yTravel == 0);
			}

			// if the pawn is black
			if (this->color == "black" && this->currSquare.first == 6) {
				return (xTravel == -1) && (yTravel == 0)
					|| (xTravel == -2) && (yTravel == 0);
			}
			else if (this->color == "black") {
				return (xTravel == -1) && (yTravel == 0);
			}
		}
		return false;
	};

	bool 
};