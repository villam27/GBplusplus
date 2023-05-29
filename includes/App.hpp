#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

class App
{
    public:
        App();
        App(const std::string &rom_name);
        App(const std::string &rom_name, const int mode);
        ~App();
    
        void    run();

    private:
        std::string _rom_name;
        int         _mode;
};

#endif  //APP_HPP