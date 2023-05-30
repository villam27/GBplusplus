#include <GameWindow.hpp>

GameWindow::GameWindow()
    : RenderWindow(sf::VideoMode(RESOLUTION_W, RESOLUTION_H),
                                "GBpp", sf::Style::Close)
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

void    GameWindow::reOpen(int scale)
{
    if (!isOpen())
        create(sf::VideoMode(RESOLUTION_W, RESOLUTION_H), "GBpp", sf::Style::Close);
    setSize(sf::Vector2u(RESOLUTION_W * scale, RESOLUTION_H * scale));       
}

void    GameWindow::run(void)
{
    if (isOpen())
    {
        while (pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
                close();
        }
        clear();
        draw(_game_screen->getSprite());
        display();
    }
}