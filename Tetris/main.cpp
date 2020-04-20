#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "config.h";
#include "Board.h";

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(config::WINDOW_WIDTH, config::WINDOW_HEIGHT), "Tetris");

	// Setup main classes for Tetris game
	Board board;

	// Prevent events from firing constantly
	bool isKeyPressed = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();		

			if ((event.type == sf::Event::KeyPressed) && !isKeyPressed)
			{
				isKeyPressed = true;
				if (event.key.code == sf::Keyboard::A)
				{
					board.setTile(rand() % config::BOARD_ROW_COUNT, rand() % config::BOARD_COL_COUNT, sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					board.resetBoard();
				}
			}

			if ((event.type == sf::Event::KeyReleased) && isKeyPressed)
			{
				isKeyPressed = false;
			}
		}

		// Game update

		// Graphics update
		window.clear();
		board.draw(window);
		window.display();
	}

	return 0;
}