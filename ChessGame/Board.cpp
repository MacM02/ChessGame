// board.cpp
#include <iostream>
#include "board.h"
#include "piece.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"

namespace chess {

	/// <summary>
	/// Board contructor that initializes an empty board.
	/// </summary>
	Board::Board() {

		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {

				// inserting rooks
				if ((row == 0 && col == 0) || (row == 0 && col == 7)) {
					placePiece(std::make_unique<Rook>("white", std::pair<int, int>(row, col)), row, col);
				}
				else if ((row == 7 && col == 0) || (row == 7 && col == 7)) {
					placePiece(std::make_unique<Rook>("black", std::pair<int, int>(row, col)), row, col);
				}
				
				// inserting knights
				else if ((row == 0 && col == 1) || (row == 0 && col == 6)) {
					placePiece(std::make_unique<Knight>("white", std::pair<int, int>(row, col)), row, col);
				}
				else if ((row == 7 && col == 1) || (row == 7 && col == 6)) {
					placePiece(std::make_unique<Knight>("black", std::pair<int, int>(row, col)), row, col);
				}

				// inserting bishops
				else if ((row == 0 && col == 2) || (row == 0 && col == 5)) {
					placePiece(std::make_unique<Bishop>("white", std::pair<int, int>(row, col)), row, col);
				}
				else if ((row == 7 && col == 2) || (row == 7 && col == 5)) {
					placePiece(std::make_unique<Bishop>("black", std::pair<int, int>(row, col)), row, col);
				}

				// inserting kings
				else if ((row == 0) && (col == 3)) {
					placePiece(std::make_unique<King>("white", std::pair<int, int>(row, col)), row, col);
				}
				else if ((row == 7) && (col == 3)) {
					placePiece(std::make_unique<King>("black", std::pair<int, int>(row, col)), row, col);
				}

				// inserting queens
				else if ((row == 0) && (col == 4)) {
					placePiece(std::make_unique<Queen>("white", std::pair<int, int>(row, col)), row, col);
				}
				else if ((row == 7) && (col == 4)) {
					placePiece(std::make_unique<Queen>("black", std::pair<int, int>(row, col)), row, col);
				}

				// inserting pawn's
				else if (row == 1) {
					placePiece(std::make_unique<Pawn>("white", std::pair<int, int>(row, col)), row, col);
				}
				else if (row == 6) {
					placePiece(std::make_unique<Pawn>("black", std::pair<int, int>(row, col)), row, col);
				}

				// otherwise fill the board with null pointers
				else {
					this->board[row][col] = nullptr;
				}
			}
		}
	}

	/// <summary>
	/// Allows a piece to move across the board.
	/// </summary>
	void Board::move() {
		// FIXME: not implemented
		// do I even need this? Place Piece seems to have it covered?...
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

	/// <summary>
	/// Called when an attacking piece takes a defending piece on the board.
	///		-> Replaces defending piece with the attacking piece on the board and sets
	///		   old attacker's square to null.
	/// </summary>
	/// <param name="attacker"> The attacking piece. </param>
	/// <param name="defender"> The defending piece. </param>
	void Board::take(std::unique_ptr<Piece> attacker, std::unique_ptr<Piece> defender) {

		// save attacker's position to set to null
		std::pair<int, int> attackerPosition = (*attacker).getCurrSquare();
		std::pair<int, int> defenderPosition = (*defender).getCurrSquare();

		placePiece(std::move(attacker), defenderPosition.first, defenderPosition.second);

		board[attackerPosition.first][attackerPosition.second] = nullptr;
	}
}