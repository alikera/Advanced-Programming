#include <iostream>
#include <vector>
#include "Tesla.hpp"
#define TESLA_UPGRADE_DAMAGE_INCREASE 1000

using namespace std;


void Tesla::draw(Window* window)
{
	if(level == 1)
    	window->draw_img("tesla1.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
	
	if(level == 2)
    	window->draw_img("tesla2.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
    	
	if(level == 3)
    	window->draw_img("tesla3.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
}
void Tesla::draw_bullet(Window* window)
{
    bullet->draw_tesla_bullet(window);
}
void Tesla::damage_enemy(enemies_t enemies)
{
    Point invalid;
    invalid.x = -100;
    invalid.y = -100;
    if(bullet->get_bullet_position().first == my_enemy->get_enemy_position().first &&
        bullet->get_bullet_position().second == my_enemy->get_enemy_position().second)
    {
        my_enemy->set_health(-damage);
        bullet->set_bullet_position(invalid);
    }
}
void Tesla::upgrade_damage()
{
	damage += TESLA_UPGRADE_DAMAGE_INCREASE;
}
