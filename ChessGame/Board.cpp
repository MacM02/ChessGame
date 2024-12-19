// board.cpp

#include <iostream>
#include "piece.cpp"
#include "rook.cpp"

class Board {
protected:
	/// <summary>
	/// The board that we will play on.
	///		- Represented as a two-dimensional array.
	///		- Playing with the convention that white begins 
	/// </summary>
	std::unique_ptr<Piece> board[8][8];

public:
	/// <summary>
	/// Board contructor that initializes an empty board.
	/// </summary>
	Board() {

		// initializing the board tiles to hold null pointers.
		// FIXME: add if statements for all pieces!
		// do I need to fill it with nullptr's initially? Or is this alright?
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {

				// inserting rooks
				if ((row == 0 && col == 0) || (row == 0 && col == 7)) {
					placePiece(std::make_unique<Rook>("rook", "white", std::pair<int, int>(row, col)));
				}
				else if ((row == 7 && col == 0) || (row == 7 && col == 7)) {
					placePiece(std::make_unique<Rook>("rook", "black", std::pair<int, int>(row, col)));
				}
			}
		}
	}

	/// <summary>
	/// Allows a piece to move across the board.
	/// </summary>
	void move() {
		
	}

private:

	/// <summary>
	/// Places a piece on the board.
	/// </summary>
	/// <param name="row"> The row that we will place the piece on. </param>
	/// <param name="col"> The column that we will place the piece on. </param>
	void placePiece(std::unique_ptr<Piece> piece) {

		// extracting the current square of the piece as a pair
		std::pair<int, int> currSquare = piece->getCurrSquare();

		// inserting the pointer into the board array
		this->board[currSquare.first][currSquare.second] = std::move(piece);
	}
};

