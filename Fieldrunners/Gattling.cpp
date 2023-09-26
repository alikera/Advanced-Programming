#include <iostream>
#include <vector>
#include "Gattling.hpp"
#define GATTLING_UPGRADE_DAMAGE_INCREASE 35

using namespace std;

void Gattling::draw(Window* window)
{
    if(level == 1)
    {
        if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Gdown1.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("G1down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Gup1.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("G1up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
    }
    
    if(level == 2)
    {
        if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Gdown2.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("G2down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Gup2.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("G2up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
    }
		
	if(level == 3)
	{
	    if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Gdown3.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("G3down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Gup3.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("G3up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
	}
}
void Gattling::draw_bullet(Window* window)
{
    bullet->draw_gattling_bullet(window);
}
void Gattling::damage_enemy(enemies_t enemies)
{
    Point invalid;
    invalid.x = -100;
    invalid.y = -100;
    if(bullet->get_bullet_position().first == my_enemy->get_enemy_position().first &&
        bullet->get_bullet_position().second == my_enemy->get_enemy_position().second)
    {
        bullet->set_bullet_position(invalid);
        if(my_enemy->get_killing_reward() == 10)
            return;
        my_enemy->set_health(-damage);
    }
}
void Gattling::upgrade_damage()
{
	damage += GATTLING_UPGRADE_DAMAGE_INCREASE;
}