#ifndef TETRISCONTROLLER_H
#define TETRISCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "config.h";
#include "Board.h";
#include "BlockData.h";

class TetrisController
{
private:
	
	// Block movement
	sf::Vector2i blockGridPosition;

	// Timer
	sf::Clock clock;

	// Test
	BlockData oBlock;

public:
	TetrisController();

	void reset();
	void resetBlock();
	void onKeyPress(sf::Keyboard::Key keyCode, Board& board);
	void update(Board& board);
};

#endif
