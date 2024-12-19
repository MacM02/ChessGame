#pragma once
#include "piece.cpp"

/// <summary>
/// This class represents a Rook on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class Rook : public Piece {
	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Rook(std::string pieceName, std::pair<int, int> currSquare)
		: Piece(pieceName, currSquare) {};

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool Piece::isValidMove(std::pair<int, int> destSquare) const override {
		if (isValidSquare(destSquare)) {

			// returns true if exactly 1 on the conditions is true and false otherwise
			return (currSquare.second == destSquare.second) ^ (currSquare.first == currSquare.first);
		}

		return false;
	};
};