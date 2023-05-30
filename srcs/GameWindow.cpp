#include <GameWindow.hpp>

GameWindow::GameWindow()
    : RenderWindow(sf::VideoMode(GAME_WIN_W, GAME_WIN_H),
                                "GBpp")
{
    setFramerateLimit(GAME_WIN_FRAMERATE);
}

GameWindow::~GameWindow()
{
}

void    GameWindow::setGameScreen(GameScreen *game_screen)
{
    _game_screen = game_screen;
}

void    GameWindow::run(void)
{
    while (pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            close();
    }
    clear();
    //sf::Sprite  sp((*_game_screen).getTexture());
    draw(_game_screen->getSprite());
    display();
}