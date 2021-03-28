#ifndef TETRISCONTROLLER_H
#define TETRISCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "config.h";
#include "Board.h";
#include "Block.h";

enum BlockType { Line, Square, TShape, LShape, RevLShape, ZShape, RevZShape, COUNT };

class TetrisController
{
private:

	// Block movement
	sf::Vector2i blockGridPosition;

	// Timer
	sf::Clock clock;

	// Orientation
	Orientation currentOrientation = Orientation::Up;

	// Create all possible block drawing data for display
	// Block.cpp will take the BlockData and draw the right display according to the current rotation	
	static const BlockData blockDataList[7];
	static const sf::Color blockColorList[5];
	static BlockData getBlockData();
	static sf::Color getBlockColor();

	void copyToBoard(Board& board);

public:
	TetrisController(sf::Vector2f renderPosition);

	// Moving block controlled by input
	Block block;

	void reset();
	void resetBlock();
	bool onKeyPress(Board& board);
	void moveBlockOnGrid(Board& board, int deltaX, int deltaY);
	void moveBlockBottom(Board& board);
	void drawBlock(sf::RenderWindow& window);
	void update(Board& board);
};

#endif
