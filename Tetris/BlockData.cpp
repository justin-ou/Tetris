#include "BlockData.h"

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
}

void BlockData::reset()
{

}

const BlockArray<bool, 2>& BlockData::getBlock()
{
	return block;
}
