// board.h
#pragma once
#include <iostream>
#include "piece.h"

namespace chess {
	class Board {
	protected:
		std::unique_ptr<Piece> board[8][8];


	public:
		/// <summary>
		/// Board contructor that initializes an empty board.
		/// </summary>
		Board();

		/// <summary>
		/// Allows a piece to move across the board.
		/// </summary>
		void move();

		/// <summary>
		/// Places a piece on the board.
		/// </summary>
		/// <param name="row"> The row that we will place the piece on. </param>
		/// <param name="col"> The column that we will place the piece on. </param>
		void placePiece(std::unique_ptr<Piece> piece, int row, int col);

		/// <summary>
		/// Called when an attacking piece takes a defending piece on the board.
		///		-> Replaces defending piece with the attacking piece on the board and sets
		///		   old attacker's square to null.
		/// </summary>
		/// <param name="attacker"> The attacking piece. </param>
		/// <param name="defender"> The defending piece. </param>
		void take(std::unique_ptr<Piece> attacker, std::unique_ptr<Piece> defender);
	};
}