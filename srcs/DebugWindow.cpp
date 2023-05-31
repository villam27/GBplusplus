#include <DebugWindow.hpp>

DebugWindow::DebugWindow()
    : RenderWindow(sf::VideoMode(DEBUG_WIN_W, DEBUG_WIN_H),
                                "GBpp Debug")
{
    setFramerateLimit(DEBUG_WIN_FRAMERATE);
    ImGui::SFML::Init(*this, true);
    _scale = MIN_SCALE;
}

DebugWindow::~DebugWindow()
{
}

void    DebugWindow::setGameScreen(GameScreen *game_screen)
{
    _game_screen = game_screen;
}

void    DebugWindow::setGameWindow(GameWindow *game_window)
{
    _game_win = game_window;
}

void    DebugWindow::setRamAddr(u_int8_t *ram_ptr)
{
    _ram_ptr = ram_ptr;
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
    showGameWindow();
    clear();    
    ImGui::SFML::Render(*this);
    display();
}

void    DebugWindow::showGameWindow(void)
{
    static MemoryEditor mem_editor;

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("Game", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar);
    ImGui::BeginMenuBar();
    if (ImGui::BeginMenu("File"))
    {
        if (ImGui::MenuItem("Open rom", "Ctrl+O")) { }
        if (ImGui::MenuItem("Close rom", "Ctrl+W"))  { }
        ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
    ImGui::Image(*_game_screen);
    if (ImGui::Button("open to window"))
        _game_win->reOpen(_scale);
    if (ImGui::SliderInt("Game window Scale", &_scale, MIN_SCALE, MAX_SCALE))
        _game_win->setSize(sf::Vector2u(RESOLUTION_W * _scale, RESOLUTION_H * _scale));
    ImGui::End();
    mem_editor.DrawWindow("Ram", _ram_ptr, TOTAL_RAM);
}