#include "BlockData.h"
#include <iostream>

BlockData::BlockData(array<int, config::BLOCK_DATA_LENGTH> blockConfig) :
	block(move(blockConfig))
{	
}

void BlockData::setBlockArray(Orientation orientation, BlockArray<bool, config::BLOCK_DATA_LENGTH>& blockArray)
{
	int blockBitMask = getBlockBitmask(orientation);
	int blockBitIndex = 1;

	for (auto i = 0; i < blockArray.size(); ++i)
	{
		for (auto j = 0; j < blockArray[i].size(); ++j)
		{
			// If blockBitMask is not empty, it should be drawn
			blockArray[i][j] = false;
			if ((blockBitMask & blockBitIndex) != 0)
			{
				blockArray[i][j] = true;
			}

			// Move bitMask index
			blockBitMask >>= 1;
		}
	}
}

const int BlockData::getBlockBitmask(Orientation orientation)
{
	int index = static_cast<int>(orientation);
	return block[index];
}
