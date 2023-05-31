#include <App.hpp>
#include <DebugWindow.hpp>

int main(void)
{
    std::ifstream   rom_file;
    uint8_t         ram[8192];

    memset(ram, 0, 8190);
    rom_file.open("roms/acid2.gbc", std::ios::in | std::ios::binary);
    rom_file.read((char *)ram, 8192);
    for (int i = 0; i < 8192; i++)
    {
        if (ram[i] == 0)
            printf("0x%X ", ram[i]);
        else
            printf("\033[1;31m0x%X\033[0m ", ram[i]);
    }
    std::cout << std::endl;
    App app("roms/acid2.gbc");

    app.run();
}

/*
int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::ShowDemoWindow();

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
*/