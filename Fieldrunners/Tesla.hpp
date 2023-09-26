#ifndef TESLA_HPP
#define TESLA_HPP 
#include "Tower.hpp"

class Tesla: public Tower 
{
public:
    Tesla(int damage_, int upgrade_cost_) : Tower(damage_, upgrade_cost_) {};
    void draw(Window* window);
	void upgrade_damage();
private:
    void draw_bullet(Window* window);
	void damage_enemy(enemies_t enemies);
	void set_bullet_delay() { bullet_delay = 30; }
};

#endif