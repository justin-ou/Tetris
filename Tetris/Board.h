
#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <array>

#include "config.h";
#include "Block.h";

using namespace std;

template<typename T>
using TileArray = array < array<T, config::BOARD_COL_COUNT>, config::BOARD_ROW_COUNT>;

class Board 
{
	struct Tile
	{
		sf::Color	color;
		bool		isActive;
	};

private:

	// Draw the board 
	sf::Vector2f		boardPosition;
	sf::RectangleShape	boardBg;

	TileArray<Tile>					tileArr;
	TileArray<sf::RectangleShape>	tileShapeArr;
	
	bool isTileValid(size_t  row, size_t col);
	bool isTileInBoard(size_t  row, size_t col);
	void resetTile(Tile& tileReference);

public:
	Board();

	sf::Vector2f getBoardPosition();
	void resetBoard();
	void setTile(size_t row, size_t col, const sf::Color& color, bool isActive = true);
	bool isBlockValid(sf::Vector2i& blockGridPosition, Block& block);
	bool isBlockBottom(sf::Vector2i blockGridPosition, Block& block);
	void draw(sf::RenderWindow& window);
};
#endif
