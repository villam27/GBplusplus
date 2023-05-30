#include <App.hpp>

App::App() : _mode(0)
{
    //_game_screen.setScale(3);
    _circle.setRadius(10);
    _circle.setFillColor(sf::Color::Blue);
    _circle.setPosition(0, 0);
    _game_win.setGameScreen(&_game_screen);
    _debug_win.setGameScreen(&_game_screen);
}

App::App(const std::string &rom_name) : _rom_name(rom_name), _mode(0)
{

}

App::App(const std::string &rom_name, const int mode) : _rom_name(rom_name), _mode(mode)
{

}

App::~App()
{

}

void    App::run()
{
    std::cout << "Run" << std::endl;
    int dir = 2;
    while (_debug_win.isOpen() && _game_win.isOpen())
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