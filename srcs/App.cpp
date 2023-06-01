#include <App.hpp>

App::App() : _mode(0)
{
    _circle.setRadius(10);
    _circle.setFillColor(sf::Color::Blue);
    _circle.setPosition(0, 0);
    _game_win.setGameScreen(&_game_screen);
    _game_win.close();
    _debug_win.setGameScreen(&_game_screen);
    _debug_win.setGameWindow(&_game_win);
}

App::App(const std::string &rom_name) : _rom_name(rom_name), _mode(0)
{
    _rom_file.open(_rom_name, std::ios::in | std::ios::binary);
    _ram.loadData(_rom_file);
    _circle.setRadius(2);
    _circle.setFillColor(sf::Color::Blue);
    _circle.setPosition(0, 0);
    _game_win.setGameScreen(&_game_screen);
    _game_win.close();
    _debug_win.setGameScreen(&_game_screen);
    _debug_win.setGameWindow(&_game_win);
    _debug_win.setRamAddr(_ram.getData(0));
}

App::App(const std::string &rom_name, const int mode) : _rom_name(rom_name), _mode(mode)
{

}

App::~App()
{
    _rom_file.close();
}

void    App::run()
{
    std::cout << "Run" << std::endl;
    int dir = 2;
    while (_debug_win.isOpen())
    {
        _circle.move(dir, 0);
        if (_circle.getPosition().x > 100)
            dir = -2;
        if (_circle.getPosition().x < 0)
            dir = 2;
        _game_screen.clear(sf::Color::Cyan);
        _game_screen.draw(_circle);
        _debug_win.run();
        _game_win.run();
    }
}