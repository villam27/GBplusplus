#ifndef DEBUG_WIN
#define DEBUG_WIN

#include <GameWindow.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <imgui_memory_editor.h>
#include <Ram.hpp>

#define DEBUG_WIN_W         800
#define DEBUG_WIN_H         600
#define DEBUG_WIN_FRAMERATE 60
#define MIN_SCALE           1
#define MAX_SCALE           5

class DebugWindow : public sf::RenderWindow
{
    public:
        DebugWindow(void);
        ~DebugWindow(void);

        void    setGameScreen(GameScreen *game_screen);
        void    setGameWindow(GameWindow *game_window);
        void    setRamAddr(u_int8_t *_ram_ptr);
        void    run(void);
        sf::RenderTexture *_tiles;

    private:
        sf::Event           _event;
        sf::Clock           _delta_clock;
        GameWindow          *_game_win;
        GameScreen          *_game_screen;
        uint8_t             *_ram_ptr;

        int                 _scale;

        /*  GUI Function    */
        void    showGameWindow(void);
};

#endif  //DEBUG_WIN