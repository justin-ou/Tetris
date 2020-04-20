
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

	// Const variables
	const sf::Color DARKEN_COLOR = sf::Color(30, 30, 30, 0);

	// Draw the board 
	sf::Vector2f		boardPosition;
	sf::RectangleShape	boardBg;
	TileArray<Tile>		tileArr;
	
	void resetTile(Tile& tileReference);

public:
	Board();

	void resetBoard();
	void setTile(int row, int col, const sf::Color& color);
	bool isBlockValid(sf::Vector2i& blockGridPosition, BlockData& block);
	void draw(sf::RenderWindow& window);
};
#endif
