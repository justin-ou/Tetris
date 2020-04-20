#ifndef CONFIG_H
#define CONFIG_H

namespace config
{
	// Board properties
	constexpr int BOARD_COL_COUNT = 10;
	constexpr int BOARD_ROW_COUNT = 22;

	// Use extern here to potentially read the values in from an external file from config.cpp
	// Window properties
	extern const int WINDOW_HEIGHT;
	extern const int WINDOW_WIDTH;	

	// Block properties
	extern const int BLOCK_SIZE;
	extern const float BLOCK_FALL_DELAY;
}

#endif
