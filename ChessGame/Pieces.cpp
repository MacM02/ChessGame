#include <iostream>

/// <summary>
/// A piece on the chess board.
/// </summary>
class Piece {
protected:
	/// <summary>
	/// The name of the piece
	/// </summary>
	std::string name;

	/// <summary>
	/// Represents a piece's current status on the board.
	/// </summary>
	bool inPlay;

	/// <summary>
	/// The current square that the piece resides on.
	///			--> access through (.first and .second)
	///			--> Note: A pair are contiguous blocks of memory stuck together. Groups data together to access easily.
	/// </summary>
	std::pair<int, int> currSquare;

public:

	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Piece(std::string name, std::pair<int, int> currSquare)
			: name(name), currSquare(currSquare), inPlay(true) {}

	/// <summary>
	/// Virtual destructor.
	///		- FIXME: Set as default for now. May change later.
	/// </summary>
	virtual ~Piece() = default;

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool isValidMove(std::pair<int, int> destSquare) const = 0;
};

// -----> Piece classes

/// <summary>
/// This class represents a Rook on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class Rook : public Piece {

	/// <summary>
	/// The name of the piece
	/// </summary>
	std::string name;

	/// <summary>
	/// Represents a piece's current status on the board.
	/// </summary>
	bool inPlay;

	/// <summary>
	/// The current square that the piece resides on.
	///			--> access through (.first and .second)
	///			--> Note: A pair are contiguous blocks of memory stuck together. Groups data together to access easily.
	/// </summary>
	std::pair<int, int> currSquare;

	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Rook(std::string pieceName, std::pair<int, int> currSquare) 
			: Piece( pieceName, currSquare) {};

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool Piece::isValidMove(std::pair<int, int> destSquare) const override {
		if ((destSquare.first > 7 || destSquare.first < 0) || (destSquare.second > 7 || destSquare.second < 0)) {
			return false;
		}

		// returns true if exactly 1 on the conditions is true and false otherwise
		return (currSquare.second == destSquare.second) ^ (currSquare.first == currSquare.first);
	};
};

/// <summary>
/// This class represents a Bishop on the chess board and inherits methods its abstract class 'Piece'.
/// </summary>
class Bishop : public Piece {

	/// <summary>
	/// The name of the piece
	/// </summary>
	std::string name;

	/// <summary>
	/// Represents a piece's current status on the board.
	/// </summary>
	bool inPlay;

	/// <summary>
	/// The current square that the piece resides on.
	/// </summary>
	std::pair<int, int> currSquare;

	/// <summary>
	/// Piece constructor.
	/// </summary>
	/// <param name="name"> Name of the piece. </param>
	/// <param name="currSquare"> The piece's current square as a pair. </param>
	Bishop(std::string pieceName, std::pair<int, int> currSquare)
		: Piece(pieceName, currSquare) {};

	/// <summary>
	/// Checks the validity of the piece's move.
	/// </summary>
	/// <returns> True if the piece can move in that direction and false if not. </returns>
	virtual bool Piece::isValidMove(std::pair<int, int> destSquare) const override {
		if ((destSquare.first > 7 || destSquare.first < 0) || (destSquare.second > 7 || destSquare.second < 0)) {
			return false;
		}

		// returns true if exactly 1 on the conditions is true and false otherwise
		return (currSquare.second == destSquare.second) ^ (currSquare.first == currSquare.first);
	};
};


