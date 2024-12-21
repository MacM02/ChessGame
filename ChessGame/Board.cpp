// board.cpp
#include <iostream>
#include "board.h"
#include "piece.h"
#include "rook.h"

namespace chess {

	/// <summary>
	/// Board contructor that initializes an empty board.
	/// </summary>
	Board::Board() {

		// initializing the board tiles to hold null pointers.
		// FIXME: add if statements for all pieces!
		// do I need to fill it with nullptr's initially? Or is this alright?
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {

				// inserting rooks
				if ((row == 0 && col == 0) || (row == 0 && col == 7)) {
					placePiece(std::make_unique<Rook>("white", std::pair<int, int>(row, col)), row, col);
				}
				else if ((row == 7 && col == 0) || (row == 7 && col == 7)) {
					placePiece(std::make_unique<Rook>("black", std::pair<int, int>(row, col)), row, col);
				}
			}
		}
	}

	/// <summary>
	/// Allows a piece to move across the board.
	/// </summary>
	void Board::move() {
		// FIXME: not implemented
	}

	/// <summary>
	/// Places a piece on the board.
	/// </summary>
	/// <param name="row"> The row that we will place the piece on. </param>
	/// <param name="col"> The column that we will place the piece on. </param>
	void Board::placePiece(std::unique_ptr<Piece> piece, int row, int col) {

		// inserting the pointer into the board array
		this->board[row][col] = std::move(piece);
	}
}