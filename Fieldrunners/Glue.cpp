#include <iostream>
#include <vector>
#include "Glue.hpp"
#define GLUE_UPGRADE_DAMAGE_INCREASE 10
#define GLUE_UPGRADE_DURATION_INCREASE 10

using namespace std;

void Glue::draw(Window* window)
{
    if(level == 1)
	{
	    if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Ldown1.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("L1down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Lup1.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("L1up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
	}
		
	if(level == 2)
    {
        if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Ldown2.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("L2down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Lup2.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("L2up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
    }
		
	if(level == 3)
	{
	    if(direction.first == 'S' && direction.second == 'E')
            window->draw_img("Ldown3.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'S' && direction.second == 'W')
            window->draw_img("L3down.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'E')
            window->draw_img("Lup3.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
            
        if(direction.first == 'N' && direction.second == 'W')
            window->draw_img("L3up.png", Rectangle(tower_position.x-30,tower_position.y-30,60,60));
	}
}
void Glue::draw_bullet(Window* window)
{
    bullet->draw_glue_bullet(window);
}
void Glue::damage_enemy(enemies_t enemies)
{
    Point invalid;
    invalid.x = -100;
    invalid.y = -100;
    if(bullet->get_bullet_position().first == my_enemy->get_enemy_position().first &&
        bullet->get_bullet_position().second == my_enemy->get_enemy_position().second)
    {
        for(int i = 0; i < enemies.size(); i++)
        {
            if(calculate_enemy_distance_from_bullet(enemies[i]) <= 30 * 30)
                if(enemies[i]->get_under_glue_bullet() == 0 && 
                    enemies[i]->get_killing_reward() != 10)
                    enemies[i]->decrease_movement_speed(100 - damage, slow_mo_power);
        }
        bullet->set_bullet_position(invalid);
    }
}
void Glue::upgrade_damage()
{
    damage += GLUE_UPGRADE_DAMAGE_INCREASE;
    slow_mo_power += GLUE_UPGRADE_DURATION_INCREASE;
}