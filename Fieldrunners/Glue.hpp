#ifndef GLUE_HPP
#define GLUE_HPP
#include "Tower.hpp"


class Glue: public Tower
{
public:
    Glue(int damage_, int upgrade_cost_) : Tower(damage_, upgrade_cost_) {};
    void draw(Window* window);
    void upgrade_damage();
private:
    void draw_bullet(Window* window);
	void damage_enemy(enemies_t enemies);
	void set_bullet_delay() { bullet_delay = 20; }
	int slow_mo_power = 50;
};

#endif