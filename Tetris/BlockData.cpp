#include "BlockData.h"

const sf::Color BlockData::DARKEN_COLOR = sf::Color(30, 30, 30, 0);

BlockData::BlockData()
{
	color = sf::Color::Yellow;
	
	for (auto i = 0; i < block.size(); ++i)
	{
		for (auto j = 0; j < block[i].size(); ++j)
		{
			block[i][j] = true;
		}
	}

	// 4 blocks
	sf::RectangleShape block(sf::Vector2f(config::BLOCK_SIZE, config::BLOCK_SIZE));
	block.setFillColor(color);
	block.setOutlineColor(color - BlockData::DARKEN_COLOR);
	block.setOutlineThickness(-2);
	blockShape.push_back(block);
	blockShape.push_back(block);
	blockShape.push_back(block);
	blockShape.push_back(block);

	reset();
}

void BlockData::reset()
{
	gridPosition = sf::Vector2i(0, 0);
}

void BlockData::draw(sf::RenderWindow& window)
{
	int blockShapeIndex = 0;

	for (auto i = 0; i < block.size(); ++i)
	{
		for (auto j = 0; j < block[i].size(); ++j)
		{
			if (block[i][j])
			{
				auto& block = blockShape[blockShapeIndex++];
				block.setPosition(startRenderPosition.x + (gridPosition.x + j) * config::BLOCK_SIZE, startRenderPosition.y + (gridPosition.y + i) * config::BLOCK_SIZE);
				window.draw(block);
			}
		}
	}
}

void BlockData::setPosition(sf::Vector2f newPosition)
{
	startRenderPosition = newPosition;
}

const BlockArray<bool, 2>& BlockData::getBlock()
{
	return block;
}
