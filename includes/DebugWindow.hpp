#ifndef DEBUG_WIN
#define DEBUG_WIN

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#define DEBUG_WIN_W         800
#define DEBUG_WIN_H         600
#define DEBUG_WIN_FRAMERATE 60

class DebugWindow : public sf::RenderWindow
{
    public:
        DebugWindow(void);

        void    setGameScreen(sf::RenderTexture *game_screen);
        void    run(void);

    private:
        sf::Event           _event;
        sf::Clock           _delta_clock;
        sf::RenderTexture   *_game_screen;
};

#endif  //DEBUG_WIN