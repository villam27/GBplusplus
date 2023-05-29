#ifndef GAME_WIN
#define GAME_WIN

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#define GAME_WIN_W         800
#define GAME_WIN_H         600
#define GAME_WIN_FRAMERATE 60

class GameWindow : public sf::RenderWindow
{
    public:
        GameWindow();
        ~GameWindow();
    
        void    setGameScreen(sf::RenderTexture *game_screen);
        void    run(void);

    private:
        sf::Event           _event;
        sf::RenderTexture   *_game_screen;
};

#endif  //GAME_WIN