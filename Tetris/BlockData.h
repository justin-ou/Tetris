#ifndef BLOCKDATA_H
#define BLOCKDATA_H

#include <SFML/Graphics.hpp>
#include <array>

using namespace std;

template<typename T, int size>
using BlockArray = array < array<T, size>, size>;

class BlockData
{
private:
	sf::Color			color;
	BlockArray<bool, 2> block;

public:
	BlockData();

	void reset();
	const BlockArray<bool, 2>& getBlock();
};

#endif
