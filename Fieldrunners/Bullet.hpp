#ifndef BULLET_HPP
#define BULLET_HPP
#include <vector>
#include "Enemy.hpp"

class Bullet 
{
public:
    Bullet(Point tower_position, Enemy* ptr_enemy)
    {
        bullet_position.first = tower_position.x;
        bullet_position.second = tower_position.y;
        enemy_to_fire = ptr_enemy;
    }
	void set_bullet_position(Point position);
	void draw_gattling_bullet(Window* window);
	void draw_missile_bullet(Window* window);
	void draw_tesla_bullet(Window* window);
	void draw_glue_bullet(Window* window);
	void clear_bullet(Window* window);
	std::pair<double, double> get_bullet_position() { return bullet_position; }
protected:
	std::pair<double, double> bullet_position;
	int damage;
	Enemy* enemy_to_fire;
	void follow_enemy();

};
#endif