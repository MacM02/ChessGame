#pragma once
#include <iostream>

/// <summary>
/// Abstract class that all pieces on the board must inherit from.
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

	/// <summary>
	/// Checks if a square is valid on the board.
	/// </summary>
	/// <param name="newTile"> The new square that the piece wants to move to. </param>
	/// <returns> True if it is within the constraints of the board and false otherwise. </returns>
	bool isValidSquare(std::pair<int, int> newSquare) const {
		return (newSquare.first >= 0 && newSquare.first < 8) && (newSquare.second >= 0 && newSquare.second < 8);
	}
};