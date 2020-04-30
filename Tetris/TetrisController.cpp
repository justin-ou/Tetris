#include "TetrisController.h"

TetrisController::TetrisController()
{
	resetBlock();
}

void TetrisController::reset()
{
	// Reset block
	resetBlock();
}

void TetrisController::resetBlock()
{
	// Reset block orientation
	// Reset block grid position
	blockGridPosition.x = config::BOARD_COL_COUNT * 0.5f;
	blockGridPosition.y = 0;
}

bool TetrisController::onKeyPress(Board& board)
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		board.setTile(rand() % config::BOARD_ROW_COUNT, rand() % config::BOARD_COL_COUNT, sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		board.resetBoard();
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveBlockOnGrid(board, -1, 0);
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveBlockOnGrid(board, 1, 0);
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// TODO: Use a function pointer to board's function to check if moves are valid before commiting a move
		moveBlockOnGrid(board, 0, 1);
		return true;
	}

	return false;
}

void TetrisController::moveBlockOnGrid(Board& board, int deltaX, int deltaY)
{
	sf::Vector2i tempBlockPosition(blockGridPosition);
	tempBlockPosition.x += deltaX;
	tempBlockPosition.y += deltaY;

	// Check position on grid
	if (board.isBlockValid(tempBlockPosition, block))
	{
		blockGridPosition = tempBlockPosition;
	}
}

void TetrisController::drawBlock(sf::RenderWindow& window)
{
	block.draw(window);
}

void TetrisController::update(Board& board)
{
	// Check timer
	sf::Time elapsedTime = clock.getElapsedTime();
	if (elapsedTime.asSeconds() >= config::BLOCK_FALL_DELAY)
	{
		moveBlockOnGrid(board, 0, 1);
		clock.restart();
	}		

	block.gridPosition = blockGridPosition;

	// Check if grid position is at bottom	
	// Write position of block on to board	
	// If block has set,
	// 1. Check if board has any full lines
	// 2. Remove lines that are full and drop tiles from above
	// 3. Get next block type 	
}
