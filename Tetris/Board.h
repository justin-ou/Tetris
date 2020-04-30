
#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <array>

#include "config.h";
#include "BlockData.h";

using namespace std;

template<typename T>
using TileArray = array < array<T, config::BOARD_COL_COUNT>, config::BOARD_ROW_COUNT>;

class Board 
{
	struct Tile
	{
		sf::RectangleShape	tileShape;
		bool				isActive;
	};

private:

	// Draw the board 
	sf::Vector2f		boardPosition;
	sf::RectangleShape	boardBg;
	TileArray<Tile>		tileArr;
	
	bool isTileValid(size_t  row, size_t col);
	bool isTileInBoard(size_t  row, size_t col);
	void resetTile(Tile& tileReference);

public:
	Board();

	sf::Vector2f getBoardPosition();
	void resetBoard();
	void setTile(size_t row, size_t col, const sf::Color& color, bool isActive = true);
	bool isBlockValid(sf::Vector2i& blockGridPosition, BlockData& block);
	void draw(sf::RenderWindow& window);
};
#endif
