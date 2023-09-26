#include <iostream>
#include <vector>
#include "Tower.hpp"
#define TOWER_RANGE 150 * 150

using namespace std;

void Tower::fire_enemy(Window* window, enemies_t enemies)
{
    bullet_delay++;
    if(my_enemy == NULL)
    {
        my_enemy = choose_enemy_to_fire(enemies);
        create_new_bullet();
    }
    if(my_enemy != NULL)  
    {
        if(calculate_enemy_distance(my_enemy->get_enemy_position(), tower_position) > TOWER_RANGE
            || my_enemy->get_health() <= 0)
        {
            if(bullet_is_on_air())
                draw_bullet(window);
            my_enemy = NULL;
            bullet->clear_bullet(window);
            return;
        }
        if(calculate_enemy_distance(my_enemy->get_enemy_position(), tower_position) <= TOWER_RANGE
            && my_enemy->get_health() > 0)
        {
            set_tower_direction(my_enemy->get_enemy_position());
            if(tower_cant_fire())
                return;
            draw_bullet(window);
            damage_enemy(enemies);
        }
    }
}
void Tower::create_new_bullet()
{
    Point invalid_position;
    invalid_position.x = -100;
    invalid_position.y = -100;
    Bullet* new_bullet = new Bullet(invalid_position, my_enemy);
    bullet = new_bullet;
}
Enemy* Tower::choose_enemy_to_fire(enemies_t enemies)
{
    Enemy* enemy_to_fire = NULL;
    int min_distance_enemy = TOWER_RANGE;
    for(int i=0; i < enemies.size(); i++)
    {
        if(calculate_enemy_distance(enemies[i]->get_enemy_position(),tower_position) <= min_distance_enemy)
        {
            enemy_to_fire = enemies[i];
            min_distance_enemy = calculate_enemy_distance(enemies[i]->get_enemy_position(), tower_position);
        }
    }
    return enemy_to_fire;
}
bool Tower::bullet_is_on_air()
{
    if(bullet->get_bullet_position().first == tower_position.x)
        return false;
    if(bullet->get_bullet_position().first != my_enemy->get_enemy_position().first &&
        bullet->get_bullet_position().second != my_enemy->get_enemy_position().second)
        return true;
    else
        return false;
}
double Tower::calculate_enemy_distance_from_bullet(Enemy* enemy)
{
    return (enemy->get_enemy_position().first - bullet->get_bullet_position().first) *
            (enemy->get_enemy_position().first - bullet->get_bullet_position().first) +
            (enemy->get_enemy_position().second - bullet->get_bullet_position().second) *
            (enemy->get_enemy_position().second - bullet->get_bullet_position().second);
}
void Tower::set_tower_direction(pair<double, double> enemy_position)
{
    if(tower_position.x <= enemy_position.first)
        direction.second = 'E';
        
    else if(tower_position.x > enemy_position.first)
        direction.second = 'W';
        
    if(tower_position.y <= enemy_position.second)
        direction.first = 'S';
        
    else if(tower_position.y > enemy_position.second)
        direction.first = 'N';
}
bool Tower::tower_cant_fire()
{
    if(bullet_delay >= 60)
    {
        bullet->set_bullet_position(tower_position);
        set_bullet_delay();
    }
    if(bullet->get_bullet_position().first == -100)
        return true;
}
void Tower::set_tower_position(Window* window, Point mouse_p)
{
    tower_position = mouse_p;
}
void Tower::set_level()
{
	level++;
}

bool Tower::occupied_by_tower(Point mouse_p)
{
    if(abs(tower_position.x - mouse_p.x) <= 30 && abs(tower_position.y - mouse_p.y) <= 30)
        return true;
}
bool Tower::tower_is_upgradable(Point mouse_p)
{
	if(occupied_by_tower(mouse_p) && level < 3)
		return true;
	else
		return false;
}