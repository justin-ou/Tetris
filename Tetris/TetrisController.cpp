#include "TetrisController.h"

// Line, Square, TShape, LShape, RevLShape, ZShape, RevZShape, COUNT
const BlockData TetrisController::blockDataList[7] =
{
	BlockData({ 240, 8738, 240, 8738 }),
	BlockData({ 1632, 1632, 1632, 1632 }),
	BlockData({ 624, 562, 114, 610 }),
	BlockData({ 113, 550, 1136, 802 }),
	BlockData({ 113, 550, 1136, 802 }),
	BlockData({ 1584, 612, 1584, 612 }),
	BlockData({ 864, 1122, 864, 1122 })
};
const sf::Color TetrisController::blockColorList[5] =
{
	sf::Color::Cyan,
	sf::Color::Yellow,
	sf::Color::Green,
	sf::Color::Magenta,
	sf::Color::Red
};

BlockData TetrisController::getBlockData()
{
	return blockDataList[rand() % BlockType::COUNT];
}

sf::Color TetrisController::getBlockColor()
{
	return blockColorList[rand() % 5];
}

TetrisController::TetrisController(sf::Vector2f renderPosition) :
	block(getBlockData(), renderPosition)
{
	resetBlock();
	block.init(getBlockColor(), getBlockData());
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
		moveBlockOnGrid(board, 0, 1);
		return true;
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
	{
		currentOrientation = static_cast<Orientation>(((int)currentOrientation + 1) % 4);
		block.setOrientation(currentOrientation);
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		moveBlockBottom(board);
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

void TetrisController::moveBlockBottom(Board& board)
{	
	// Move down until block is invalid
	sf::Vector2i tempBlockPosition(blockGridPosition);
	while (board.isBlockValid(tempBlockPosition, block))
	{
		tempBlockPosition.y++;
	}
	blockGridPosition.x = tempBlockPosition.x;
	blockGridPosition.y = tempBlockPosition.y - 1;
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
	if (board.isBlockBottom(blockGridPosition, block))
	{		
		// If not game over, clear lines and add more blocks
		if (board.isBlockValid(block.gridPosition, block))
		{
			copyToBoard(board);
			resetBlock();

			// Create new block at the top
			block.reset();
			block.init(getBlockColor(), getBlockData());
		}		
	}
}

void TetrisController::copyToBoard(Board& board)
{
	auto& blockArray = block.getBlock();
	for (auto i = 0; i < blockArray.size(); ++i)
	{
		for (auto j = 0; j < blockArray[i].size(); ++j)
		{
			if (blockArray[i][j])
			{
				// Set tile and clear lines if row is full
				board.setTile(block.gridPosition.y + i, block.gridPosition.x + j, block.getColor());
			}
		}
	}
}
