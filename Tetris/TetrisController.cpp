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

void TetrisController::onKeyPress(sf::Keyboard::Key keyCode, Board& board)
{	
	if (keyCode == sf::Keyboard::Key::Left)
	{
		blockGridPosition.x--;
		update(board);
	}
	else if (keyCode == sf::Keyboard::Key::Right)
	{
		blockGridPosition.x++;
		update(board);
	}
	else if (keyCode == sf::Keyboard::Key::Down)
	{
		// TODO: Use a function pointer to board's function to check if moves are valid before commiting a move
		blockGridPosition.y++;
		update(board);
	}	
}

void TetrisController::update(Board& board)
{
	// Check timer
	sf::Time elapsedTime = clock.getElapsedTime();
	if (elapsedTime.asSeconds() >= config::BLOCK_FALL_DELAY)
	{
		blockGridPosition.y++;
		clock.restart();
	}	

	// Check if grid position is at bottom	
	// Write position of block on to board	
	// If block has set,
	// 1. Check if board has any full lines
	// 2. Remove lines that are full and drop tiles from above ** WHAT DATA STRUCTURE TO USE TO CLEAR LINES?
	// 3. Get next block type 	
}
