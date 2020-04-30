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

public:
	TetrisController();

	// Test
	BlockData block;

	void reset();
	void resetBlock();
	bool onKeyPress(Board& board);
	void moveBlockOnGrid(Board& board, int deltaX, int deltaY);
	void drawBlock(sf::RenderWindow& window);
	void update(Board& board);
};

#endif
