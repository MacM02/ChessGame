// piece.h
#pragma once
#include <iostream>
#include <utility>
#include <string>

namespace chess {
	
	/// <summary>
	/// An abstract class that holds all piece functionality.
	/// </summary>
	class Piece {
	protected:
		/// <summary>
		/// The name of the piece
		/// </summary>
		std::string name;

		/// <summary>
		/// The color of the piece.
		///		- Either white or black.
		/// </summary>
		std::string color;

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
		Piece(std::string name, std::string color, std::pair<int, int> currSquare);

		/// <summary>
		/// Virtual destructor.
		/// </summary>
		virtual ~Piece() = default;

		/// <summary>
		/// Checks the validity of the piece's move.
		/// </summary>
		/// <returns> True if the piece can move in that direction and false if not. </returns>
		bool isValidMove(std::pair<int, int> destSquare) const;

		/// <summary>
		/// Checks if a square is valid on the board.
		/// </summary>
		/// <param name="newTile"> The new square that the piece wants to move to. </param>
		/// <returns> True if it is within the constraints of the board and false otherwise. </returns>
		virtual bool isValidSquare(std::pair<int, int> newSquare) const;

		/// <summary>
		/// Gets the piece's current square.
		/// </summary>
		/// <returns> A pair of ints as the current square [row, col].</returns>
		std::pair<int, int> getCurrSquare() const;
	};

}
