#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

#define SCREEN_PX       23040
#define RESOLUTION_W    160
#define RESOLUTION_H    144

class GameScreen : public sf::RenderTexture
{
    public:
        GameScreen();
        ~GameScreen();
    
        sf::Sprite  &getSprite(void);
        void        setData(char screen_date[SCREEN_PX]);
        void        setScale(unsigned scale);
    private:
        sf::Sprite  _screen_sprite;
        unsigned    _scale;
};

#endif  //GAME_SCREEN_HPP