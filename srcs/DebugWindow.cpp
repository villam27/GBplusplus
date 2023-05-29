#include <DebugWindow.hpp>

DebugWindow::DebugWindow()
    : RenderWindow(sf::VideoMode(DEBUG_WIN_W, DEBUG_WIN_H),
                                "GBpp Debug")
{
    setFramerateLimit(DEBUG_WIN_FRAMERATE);
    ImGui::SFML::Init(*this, true);
}

void    DebugWindow::setGameScreen(sf::RenderTexture *game_screen)
{
    _game_screen = game_screen;
}

void    DebugWindow::run(void)
{
    while (pollEvent(_event))
    {
        ImGui::SFML::ProcessEvent(*this, _event);

        if (_event.type == sf::Event::Closed)
            close();
    }
    ImGui::SFML::Update(*this, _delta_clock.restart());
    ImGui::ShowDemoWindow();
    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();
    clear();
    ImGui::SFML::Render(*this);
    display();
}