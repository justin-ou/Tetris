#include "Block.h"

const sf::Color Block::DARKEN_COLOR = sf::Color(70, 70, 70, 0);
const sf::Color Block::LIGHTEN_COLOR = sf::Color(60, 60, 60, 0);

Block::Block(const BlockData& newBlockData, sf::Vector2f renderPosition) :
	blockData(newBlockData),
	blockShape(sf::Vector2f(config::BLOCK_INNER_SIZE, config::BLOCK_INNER_SIZE)),
	outlineShape(sf::Vector2f(config::BLOCK_SIZE, config::BLOCK_SIZE))
{
	// Set start render position
	startRenderPosition = renderPosition;
	reset();
}

void Block::init(const sf::Color blockColor, const BlockData& newBlockData)
{
	// Set new block data used to render the block
	color = blockColor;
	blockData = newBlockData;
	setOrientation(Orientation::Up);

	// Specifiy block color 
	blockShape.setFillColor(color);

	// Specify background outline color and outline
	outlineShape.setFillColor(color - DARKEN_COLOR);
	outlineShape.setOutlineColor(color + LIGHTEN_COLOR);
	outlineShape.setOutlineThickness(-1);
}

void Block::setOrientation(Orientation orientation)
{
	blockData.setBlockArray(orientation, block);
}

void Block::reset()
{
	gridPosition = sf::Vector2i(0, 0);

	// Reset block drawing data
	for (auto i = 0; i < block.size(); ++i)
	{
		for (auto j = 0; j < block[i].size(); ++j)
		{
			block[i][j] = false;
		}
	}
}

void Block::draw(sf::RenderWindow& window)
{	
	for (auto i = 0; i < block.size(); ++i)
	{
		for (auto j = 0; j < block[i].size(); ++j)
		{
			if (block[i][j])
			{
				float xPosition = startRenderPosition.x + (gridPosition.x + j) * config::BLOCK_SIZE;
				float yPosition = startRenderPosition.y + (gridPosition.y + i) * config::BLOCK_SIZE;
				blockShape.setPosition(xPosition, yPosition);
				outlineShape.setPosition(xPosition, yPosition);
				window.draw(outlineShape);
				window.draw(blockShape);
			}
		}
	}
}

sf::Color Block::getColor()
{
	return color;
}

const BlockArray<bool, config::BLOCK_DATA_LENGTH>& Block::getBlock()
{
	return block;
}
