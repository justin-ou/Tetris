#include "Board.h"

Board::Board()
{
	// Board is in center of the screen
	float boardHeight = config::BLOCK_SIZE * config::BOARD_ROW_COUNT;
	float heightPadding = (config::WINDOW_HEIGHT - boardHeight) * 0.5f;
	float boardWidth = config::BLOCK_SIZE * config::BOARD_COL_COUNT;
	float widthPadding = (config::WINDOW_WIDTH - boardWidth) * 0.5f;

	boardPosition.x = config::WINDOW_WIDTH - widthPadding - boardWidth;
	boardPosition.y = config::WINDOW_HEIGHT - heightPadding - boardHeight;	

	// Draw the board background
	boardBg.setSize(sf::Vector2f(boardWidth, boardHeight));
	boardBg.setFillColor(sf::Color::Black);
	boardBg.setOutlineThickness(2);
	boardBg.setOutlineColor(sf::Color::White);
	boardBg.setPosition(boardPosition);

	// Initialize the board
	for (auto i = 0; i < tileArr.size(); ++i)
	{
		for (auto j = 0; j < tileArr[i].size(); ++j)
		{
			// Init rectangle shapes
			sf::RectangleShape newRectangle(sf::Vector2f(config::BLOCK_SIZE, config::BLOCK_SIZE));
			newRectangle.setPosition(boardPosition.x + j * config::BLOCK_SIZE, boardPosition.y + i * config::BLOCK_SIZE);
			tileArr[i][j].tileShape = std::move(newRectangle);
			
			resetTile(tileArr[i][j]);
		}
	}
}

sf::Vector2f Board::getBoardPosition()
{
	return boardPosition;
}

void Board::resetBoard()
{
	for (auto row = 0; row < tileArr.size(); ++row)
	{
		for (auto col = 0; col < tileArr[row].size(); ++col)
		{
			resetTile(tileArr[row][col]);
		}
	}
}

void Board::draw(sf::RenderWindow& window)
{
	// Draw the bg
	window.draw(boardBg);

	// Draw the tiles
	for (auto row = 0; row < tileArr.size(); ++row)
	{
		for (auto col = 0; col < tileArr[row].size(); ++col)
		{
			if (tileArr[row][col].isActive)
			{
				window.draw(tileArr[row][col].tileShape);
			}
		}
	}
}

bool Board::isTileValid(size_t row, size_t col)
{
	if (!isTileInBoard(row, col)) return false;
	return !tileArr[row][col].isActive;
}

bool Board::isTileInBoard(size_t row, size_t col)
{
	// Check array bounds
	return row >= config::BOARD_ROW_COUNT || col >= config::BOARD_COL_COUNT;	
}

void Board::setTile(size_t row, size_t col, const sf::Color& color, bool isActive)
{
	if (!isTileInBoard(row, col)) return;

	// Set the tile		
	auto& tile = tileArr[row][col];
	auto& tileShape = tile.tileShape;
	tileShape.setFillColor(color);
	tileShape.setOutlineColor(color - BlockData::DARKEN_COLOR);
	tileShape.setOutlineThickness(-2);

	tile.isActive = isActive;
}

bool Board::isBlockValid(sf::Vector2i & blockGridPosition, BlockData & block)
{
	// Loop through the block data and check the row/col tile
	auto& blockArray = block.getBlock();
	for (auto row = 0; row < blockArray.size(); ++row)
	{
		for (auto col = 0; col < blockArray[row].size(); ++col)
		{
			if (blockArray[row][col])
			{
				if (!isTileValid(row + blockGridPosition.y, col + blockGridPosition.x)) return false;
			}
		}
	}
	return true;
}

void Board::resetTile(Tile & tileReference)
{
	tileReference.isActive = false;
}