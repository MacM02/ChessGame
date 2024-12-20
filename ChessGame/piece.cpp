// piece.cpp
#pragma once
#include "piece.h"
#include <iostream>

namespace chess {

	Piece::Piece(std::string name, std::string color, std::pair<int, int> currSquare)
		: name(name), color(color), currSquare(currSquare), inPlay(true) {}

	bool Piece::isValidSquare(std::pair<int, int> newSquare) const {
		return (newSquare.first >= 0 && newSquare.first < 8) && (newSquare.second >= 0 && newSquare.second < 8);
	}

	std::pair<int, int> Piece::getCurrSquare() const {
		return currSquare;
	}
	
}


