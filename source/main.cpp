#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "base_logic.h"
#include "map_master.h"
#include "map_objects.h"
#include "maps.h"
#include "windows.h"
//#include "SFML/OpenGL.hpp"

int main() {
    sf::ContextSettings setting;

    setting.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(700, 720), "SFML Works!", sf::Style::Default, setting);
    window.setVerticalSyncEnabled(true);

//    glEnable(GL_TEXTURE_2D);
    USO::Aim_map test(R"(data\maps\demo_drum_go_dum.txt)");
    test.run(window);

    return 0;
}