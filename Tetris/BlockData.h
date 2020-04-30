#ifndef BLOCKDATA_H
#define BLOCKDATA_H

#include <SFML/Graphics.hpp>
#include <array>

#include "config.h";

using namespace std;

template<typename T, int size>
using BlockArray = array < array<T, size>, size>;

class BlockData
{
private:
	sf::Vector2f				startRenderPosition;
	sf::Color					color;
	BlockArray<bool, 2>			block;
	vector<sf::RectangleShape>	blockShape;

public:

	// Const variables
	static const sf::Color DARKEN_COLOR;

	sf::Vector2i gridPosition;

	BlockData();

	void reset();
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f newPosition);
	const BlockArray<bool, 2>& getBlock();
};

#endif
