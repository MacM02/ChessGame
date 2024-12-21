// bishop.h
#pragma once
#include <iostream>
#include "piece.h"

namespace chess {
	class Bishop : public Piece {

	public:
		/// <summary>
		/// Piece constructor.
		/// </summary>
		/// <param name="name"> Name of the piece. </param>
		/// <param name="currSquare"> The piece's current square as a pair. </param>
		Bishop(std::string pieceColor, std::pair<int, int> currSquare);

		/// <summary>
		/// Checks the validity of the piece's move.
		/// </summary>
		/// <returns> True if the piece can move in that direction and false if not. </returns>
		bool isValidMove(std::pair<int, int> destSquare) const ;
	};
}


