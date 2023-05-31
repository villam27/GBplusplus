#include <GameScreen.hpp>

GameScreen::GameScreen()
{
        create(RESOLUTION_W, RESOLUTION_H);
        _screen_sprite.setTexture(getTexture());
}

GameScreen::~GameScreen()
{

}

sf::Sprite  &GameScreen::getSprite(void)
{
        return (_screen_sprite);
}

void    GameScreen::setData(char screen_date[SCREEN_PX])
{
        (void)screen_date;
}

void    GameScreen::setScale(unsigned scale)
{
        _scale = scale;
        _screen_sprite.setScale(static_cast<float>(_scale),
                                static_cast<float>(_scale));
}