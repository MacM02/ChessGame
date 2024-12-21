Authors: Mack Muir-Jeffryes
Start Date: December 16th, 2024
GitHub ID: MacM02
GitHub Repo: https://github.com/MacM02/ChessGame
Commit Date: December 16th, 2024
Solution: ChessGame
Copyright: [Mack Muir-Jeffryes]

# Overview

	December 16th, 2024:
	
	Beginnging to write the our chess game. First implementations include our abstract Piece class. This class will hold
	contract over all classes that inherit the Piece class, such as the Rook, Queen,  Bishop, Pawn, King, and Knight.

	Our board will be made up of a two-dimensional array that holds Pieces. As per common chess fashion, the board will be
	an (8x8) layout.

# Estimated/Worked       Notes

	20 hrs / X							
	
# Times Worked on
	
	# Implementing Piece functionality 
	12/17-18/24

	# Added all the header files... a long process.
	12/20/24

# Notes

	Trying to understand how unique parts of the game are linked together. 

	Currently believe:

	Models - The pieces that we will use when instructing the GUI to draw according to object state.

	View - A GUI class that may be our chess_game?

	Controller - Probably our board.cpp file? As it holds all the current board data and processes movement logic, etc.