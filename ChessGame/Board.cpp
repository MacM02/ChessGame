// board.cpp

#include <iostream>
#include "Pieces.cpp"

class Board {
protected:
	/// <summary>
	/// The board that we will play on.
	///		- Represented as a two-dimensional array.
	/// </summary>
	std::unique_ptr<Piece> board[8][8];

public:
	/// <summary>
	/// Board contructor that initializes an empty board.
	/// </summary>
	Board() {

		// initializing the board tiles to hold null pointers.
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				board[row][col] = nullptr;
			}
		}
	}

	/// <summary>
	/// Allows a piece to move across the board.
	/// </summary>
	void move() {
		
	}

private:
	void placePiece() {

	}

};

