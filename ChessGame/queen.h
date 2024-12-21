// queen.h
#pragma once
#include <iostream>
#include "piece.h"

namespace chess {
	class Queen : public Piece {

	public:
		/// <summary>
		/// Piece constructor.
		/// </summary>
		/// <param name="name"> Name of the piece. </param>
		/// <param name="currSquare"> The piece's current square as a pair. </param>
		Queen(std::string pieceColor, std::pair<int, int> currSquare);

		/// <summary>
		/// Checks the validity of the piece's move.
		/// </summary>
		/// <returns> True if the piece can move in that direction and false if not. </returns>
		bool isValidMove(std::pair<int, int> destSquare) const;

		/// <summary>
		/// Assesses whether the desination square is in a straight vertical or horizontal line relative
		/// to the piece's current square.
		/// </summary>
		/// <param name="destSquare"> The destination square. </param>
		/// <returns> True if it follows a straight line and false if not. </returns>
		bool isStraight(std::pair<int, int> destSquare) const;

		/// <summary>
		/// Assesses whether the desination square is in a diagonal line relative to the piece's current square.
		/// </summary>
		/// <param name="destSquare"> The destination square. </param>
		/// <returns> True if it follows a daigonal line and false if not.</returns>
		bool isDiagonal(std::pair<int, int> destSquare) const;
	};
}
