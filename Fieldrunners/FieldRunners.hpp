#ifndef FIELD_RUNNERS_HPP
#define FIELD_RUNNERS_HPP
#include <vector>
#include "rsdl.hpp"
#include "Tower.hpp"
#include "Enemy.hpp"
#define INVALID -1


class FieldRunners {
public:
	void update(Window* window, Point &mouse_p);
	void draw_everything(Window* window, path_t enemy_path);
	void create_enemies(waves_t waves);
	void set_enemies_position(int enemy_delay, path_t enemy_path);
	void check_for_gome_over(Window* window, waves_t waves);
	void game_round_counter();
private:
	towers_t towers;
	enemies_t enemies;
	int game_round = 1;
	int user_money = 2000;
	int user_hearts = 20;
	void draw_enemies_path(Window* window, path_t enemy_path);
	void set_exact_mouse_position(Point &mouse_p);
	void build_towers(Window* window, Point &mouse_p, char pressed_char);
	void build_gattling(Window* window, Point &mouse_p);
	void build_missile(Window* window, Point &mouse_p);
	void build_tesla(Window* window, Point &mouse_p);
	void build_glue(Window* window, Point &mouse_p);
	void upgrade_tower(Point &mouse_p);
	void draw_towers(Window* window);
	void create_the_runner(path_t wave, Point start_point);
    void create_stubborn(std::vector<int> wave, Point start_point);
    void create_super_trooper(std::vector<int> wave, Point start_point);
    void create_scrambler(std::vector<int> wave, Point start_point);
	void draw_enemies(Window* window, path_t enemy_path);
	void delete_enemies(path_t enemy_path);
	void delete_killed_enemies(int i);
    void delete_survived_enemies(int i, path_t enemy_path);
};

#endif