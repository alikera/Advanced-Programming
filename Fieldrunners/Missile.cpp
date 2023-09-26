#include <iostream>
#include <vector>
#include "Missile.hpp"
#define MISSILE_UPGRADE_DAMAGE_INCREASE 75
using namespace std;

void Missile::draw(Window* window)
{
	if(level == 1)
	{
	    if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Mdown1.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("M1down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Mup1.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("M1up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
	}
		
	if(level == 2)
    {
        if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Mdown2.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("M2down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Mup2.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("M2up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
    }
		
	if(level == 3)
	{
	    if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Mdown3.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("M3down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Mup3.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("M3up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
	}
}
void Missile::draw_bullet(Window* window)
{
    bullet->draw_missile_bullet(window);
}

void Missile::damage_enemy(enemies_t enemies)
{
    Point invalid;
    invalid.x = -100;
    invalid.y = -100;
    if(bullet->get_bullet_position().first == my_enemy->get_enemy_position().first &&
        bullet->get_bullet_position().second == my_enemy->get_enemy_position().second)
    {
        for(int i = 0; i < enemies.size(); i++)
        {
            if(calculate_enemy_distance_from_bullet(enemies[i]) <= 50 * 50)
                enemies[i]->set_health(-damage);
        }
        bullet->set_bullet_position(invalid);
    }
}
void Missile::upgrade_damage()
{
	damage += MISSILE_UPGRADE_DAMAGE_INCREASE;
}