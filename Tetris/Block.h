#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <array>

#include "config.h";
#include "BlockData.h";

template<typename T, int size>
using BlockArray = std::array < std::array<T, size>, size>;

class Block
{
private:	

	sf::Vector2f				startRenderPosition;
	sf::RectangleShape			blockShape;
	sf::RectangleShape			outlineShape;	
	BlockData					blockData;
	sf::Color					color;

	BlockArray<bool, config::BLOCK_DATA_LENGTH> block;

public:

	// Const variables
	static const sf::Color DARKEN_COLOR;
	static const sf::Color LIGHTEN_COLOR;

	sf::Vector2i gridPosition;

	Block(const BlockData& newBlockData, sf::Vector2f renderPosition);

	void reset();
	void init(const sf::Color blockColor, const BlockData& newBlockData);
	void setOrientation(Orientation orientation);
	void draw(sf::RenderWindow& window);	
	sf::Color getColor();
	const BlockArray<bool, config::BLOCK_DATA_LENGTH>& getBlock();
};

#endif
