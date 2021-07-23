#ifndef USO_MENU_H
#define USO_MENU_H
#include <cstddef>
#include <deque>
#include <string>
#include "SFML/Graphics.hpp"
#include "base_logic.h"
#include <iostream>

namespace Menu {

enum CG {
    CREATE,
    RANDOM_GENERATE,
    NOTHING
};

enum MOD {
    ACCELERATION
};

const std::size_t MAX_SIZE = 6;
const int NUMBER_OF_MODS = 1;

struct scrolling_menu {
private:
    std::string filename;
    sf::Text text;
    sf::Font font;
    int delta{};
    std::vector<std::string> list_of_maps;
    std::vector<sf::RectangleShape> blocks_of_maps_name;

public:
    scrolling_menu() = default;
    explicit scrolling_menu(std::string);
    void scrolling_down();
    void scrolling_up();
    bool push(sf::RenderWindow &, sf::Vector2f);
    void draw(sf::RenderWindow &window);


    [[nodiscard]] int get_delta() const;
    void increase_delta();
    void decrease_delta();

};

struct map_creation_menu {
    std::string filename;
    sf::Text text;
    sf::Font font;
    std::vector<sf::RectangleShape> blocks_of_map_data;
    std::vector<std::string> list_of_data;
    std::vector<std::vector<std::string>> list_of_default_data;
    sf::RectangleShape random_map_block;
    sf::RectangleShape create_block;


    explicit map_creation_menu(std::string);
    void draw(sf::RenderWindow &);
    int get_id(sf::Vector2f) const;
    void add_new_map(const std::string &) const;
    CG create_or_generate(sf::RenderWindow &, sf::Vector2f);
    void draw_blocks_of_data(sf::RenderWindow &, sf::CircleShape &);
};

void draw(sf::RenderWindow &);
void menu(sf::RenderWindow &, BL::Game_session);
void constructor_menu(sf::Window &window);
sf::RenderWindow &set_settings();
void stop_menu(sf::RenderWindow &, BL::Game_session &);
void list_of_maps(sf::RenderWindow &);

struct mod_menu {
    sf::Font font;
    std::vector<sf::RectangleShape> mod_blocks;
    std::vector<sf::Text> list_of_mods;

    mod_menu();
    void draw(sf::RenderWindow &);
};

int get_id(std::vector<sf::RectangleShape> &, sf::Vector2f);
bool check_color(sf::Text);

float return_acceleration(sf::Text);
void change_speed(const std::string&, float);

}  // namespace Menu

#endif  // USO_MENU_H
