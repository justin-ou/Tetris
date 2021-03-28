#ifndef BLOCKDATA_H
#define BLOCKDATA_H

#include <SFML/Graphics.hpp>
#include <array>

#include "config.h";

using namespace std;

template<typename T, int size>
using BlockArray = array < array<T, size>, size>;

enum Orientation { Up, Right, Down, Left };

class BlockData
{
private:
	// 1 int representation for each orientation
	array<int, 4> block;

	const int getBlockBitmask(Orientation orientation);

public:	
	BlockData(array<int, config::BLOCK_DATA_LENGTH> blockConfig);	
	void setBlockArray(Orientation orientation, BlockArray<bool, config::BLOCK_DATA_LENGTH>& blockArray);
};

#endif
