#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <iostream>
#include <DebugWindow.hpp>
#include <GameWindow.hpp>
#include <GameScreen.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <fstream>

class App
{
	public:
		App();
		App(const std::string &rom_name);
		App(const std::string &rom_name, const int mode);
		~App();

		void    run();

	private:
		DebugWindow         _debug_win;
		GameWindow          _game_win;
		GameScreen          _game_screen;
		sf::CircleShape     _circle;
		std::string         _rom_name;
		int                 _mode;

		std::ifstream       _rom_file;
		uint8_t             _ram[TOTAL_RAM];
};

#endif  //APP_HPP