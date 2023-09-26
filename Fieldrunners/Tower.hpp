#ifndef TOWER_HPP
#define TOWER_HPP
#include <vector>
#include "Enemy.hpp"
#include "rsdl.hpp"
#include "Bullet.hpp"
#include "functions.hpp"


class Tower 
{
public:
    Tower(int damage_, int upgrade_cost_) 
    { 
        damage = damage_; 
        upgrade_cost = upgrade_cost_;
    }
	virtual void draw(Window* window) = 0;
	void set_tower_position(Window* window, Point mouse_p);
	void set_tower_direction(std::pair<double, double> enemy_position);
	bool tower_is_upgradable(Point mouse_p);
	void set_level();
	virtual void upgrade_damage() = 0;
	int get_upgrade_cost() { return upgrade_cost; };
	void fire_enemy(Window* window, enemies_t enemies);
	int get_tower_damage() { return damage; }
protected:
    Bullet* bullet;
	int damage;
	int upgrade_cost;
    Point tower_position;
    int level = 1;
    int bullet_delay = 59;
    std::pair<char, char> direction = std::make_pair('S', 'E');
    Enemy* my_enemy = NULL;
    bool occupied_by_tower(Point mouse_p);
	bool tower_cant_fire();
	void create_new_bullet();
	virtual void set_bullet_delay() = 0;
	virtual void damage_enemy(enemies_t enemies) = 0;
	virtual void draw_bullet(Window* window) = 0;
    Enemy* choose_enemy_to_fire(enemies_t enemies);
	bool bullet_is_on_air();
	double calculate_enemy_distance_from_bullet(Enemy* enemy);

};

typedef std::vector<Tower*> towers_t;

#endif