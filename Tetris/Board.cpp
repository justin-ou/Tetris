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

void Board::setTile(int row, int col, const sf::Color& color)
{
	// Check array bounds
	if (row < 0 || row >= config::BOARD_ROW_COUNT || col < 0 || col >= config::BOARD_COL_COUNT) return;

	// Set the tile		
	auto& tile = tileArr[row][col];
	auto& tileShape = tile.tileShape;
	tileShape.setFillColor(color);
	tileShape.setOutlineColor(color - DARKEN_COLOR);
	tileShape.setOutlineThickness(-2);

	tile.isActive = true;
}

bool Board::isBlockValid(sf::Vector2i & blockGridPosition, BlockData & block)
{
	return false;
}

void Board::resetTile(Tile & tileReference)
{
	tileReference.tileShape.setFillColor(sf::Color::Black);
	tileReference.tileShape.setOutlineColor(sf::Color::Black);
	tileReference.tileShape.setOutlineThickness(0);
	tileReference.isActive = false;
}