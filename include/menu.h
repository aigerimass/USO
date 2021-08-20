#ifndef USO_MENU_H
#define USO_MENU_H

//#include <cstddef>
//#include <deque>
//#include <string>
//#include "SFML/Graphics.hpp"
#include "base_logic.h"
//#include <iostream>
//#include <functional>

#include "loading_menu.h"
//#include "main.h"
#include "menu_objects.h"

extern std::string new_map_name;

namespace Menu {

enum CG {
    CREATE,
    RANDOM_GENERATE,
    NOTHING
};

enum MOD {
    ACCELERATION
};

const int NUMBER_OF_MODS = 1;
sf::RenderWindow &set_settings();

struct menu {
protected:

    sf::Vector2f prev_win_size;
    sf::Vector2f prev_win_pos;
    bool ctrl_pressed;
    float coef;
    std::vector<Button> buttons;
    void check_scale();
public:

    void draw(sf::RenderWindow &);
    virtual Action check_event(sf::RenderWindow &, sf::Event, BL::Game_session &);
    virtual void run(sf::RenderWindow &, BL::Game_session &);
    virtual ~menu() = default;
};

struct main_menu final : menu {
public:
    explicit main_menu();
    Action check_event(sf::RenderWindow &, sf::Event, BL::Game_session &) override;
    void run(sf::RenderWindow &, BL::Game_session &) override;
};

struct stop_menu final : menu {

    explicit stop_menu(BL::Game_status);
    Action check_event(sf::RenderWindow &, sf::Event, BL::Game_session &) override;
    void run(sf::RenderWindow &, BL::Game_session &) override;
};

struct scrolling_menu {
private:
    int delta{};
    float track_speed{};
    float scrolling_speed{};
    float gap{};
    std::size_t char_size{};
    sf::Vector2f BLOCK_SIZE;
    std::string filename;
    std::vector<sf::Text> map_names;
    sf::Font font;
    std::vector<std::string> list_of_maps;
    std::vector<sf::RectangleShape> blocks_of_map_names;
    sf::RectangleShape *first_block{};
    sf::RectangleShape *last_block{};
    sf::Text *first_map_name{};
    sf::Text *last_map_name{};

    static sf::Vector2f plus(sf::Vector2f, sf::Vector2f);
    static sf::Vector2f minus(sf::Vector2f, sf::Vector2f);
    void scrolling(const std::function<sf::Vector2f(sf::Vector2f, sf::Vector2f)>&);
    bool push(sf::RenderWindow &, sf::Vector2f);

    int number_of_blocks() const;
    void blocks_movement();
    void hide_protruding_blocks(sf::RenderWindow &) const;
    void draw(sf::RenderWindow &window);
    void rebuild();
    Action check_event(sf::RenderWindow &, sf::Event);
public:
    scrolling_menu() = default;
    explicit scrolling_menu(std::string);
    void run(sf::RenderWindow &);
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
    CG create_or_generate(sf::RenderWindow &, sf::Vector2f);
    void draw_blocks_of_data(sf::RenderWindow &, sf::CircleShape &);
    void fix_map_name(std::string &) const;
};

struct mod_menu {
    sf::Font font;
    std::vector<sf::RectangleShape> mod_blocks;
    std::vector<sf::Text> list_of_mods;

    mod_menu();
    void draw(sf::RenderWindow &);
    static int get_id(std::vector<sf::RectangleShape> &, sf::Vector2f);
    static bool check_color(const sf::Text&);
    static float return_acceleration(const sf::Text&);

};

void change_speed(const std::string&, float);

}  // namespace Menu

#endif  // USO_MENU_H
