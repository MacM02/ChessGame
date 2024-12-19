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

		// FIXME: if (pawn is on starting square) { allow two steps forward };
		// starting row for white = 1
		// starting row for black = 6
		if (isValidSquare(destSquare)) {

			// if the pawn is white
			if (this->color == "white") {
				return ((destSquare.first - currSquare.first) == 1) && (destSquare.second == currSquare.second);
			}

			// if the pawn is black
			return ((destSquare.first - currSquare.first) == -1) && (destSquare.second == currSquare.second);
		}

		return false;
	};
};