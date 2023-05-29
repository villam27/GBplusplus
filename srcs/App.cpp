#include <App.hpp>

App::App() : _mode(0)
{

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
    while (_debug_win.isOpen())
    {
        _debug_win.run();
    }
    
}