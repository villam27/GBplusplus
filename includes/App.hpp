#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <iostream>
#include <DebugWindow.hpp>

class App
{
    public:
        App();
        App(const std::string &rom_name);
        App(const std::string &rom_name, const int mode);
        ~App();
    
        void    run();

    private:
        DebugWindow _debug_win;
        std::string _rom_name;
        int         _mode;
};

#endif  //APP_HPP