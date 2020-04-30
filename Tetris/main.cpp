#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "config.h";
#include "Board.h";
#include "TetrisController.h";

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(config::WINDOW_WIDTH, config::WINDOW_HEIGHT), "Tetris");

	// Setup main classes for Tetris game
	Board board;
	TetrisController controller;

	// Init
	controller.block.setPosition(board.getBoardPosition());

	// Prevent events from firing constantly
	bool isKeyPressed = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyReleased && isKeyPressed)
			{
				isKeyPressed = false;
			}
		}

		if (!isKeyPressed)
		{
			if (controller.onKeyPress(board))
			{
				isKeyPressed = true;
			}
		}		

		// Game update
		controller.update(board);

		// Graphics update
		window.clear();		
		board.draw(window);
		controller.drawBlock(window);		
		window.display();
	}

	return 0;
}