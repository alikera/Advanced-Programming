#ifndef MISSILE_HPP
#define MISSILE_HPP
#include "Tower.hpp"

class Missile: public Tower 
{
public:
    Missile(int damage_, int upgrade_cost_) : Tower(damage_, upgrade_cost_) {};
    void draw(Window* window);
	void upgrade_damage();
private:
    void draw_bullet(Window* window);
	void set_bullet_delay() { bullet_delay = 0; }
	void damage_enemy(enemies_t enemies);
};

#endif