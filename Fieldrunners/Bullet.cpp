#include <iostream>
#include <vector>
#include "Bullet.hpp"
#define BULLET_DELTA_X 15
#define BULLET_SIZE 3
#define BULLET_COLOR BLACK

using namespace std;

void Bullet::set_bullet_position(Point position)
{
	bullet_position.first = position.x;
	bullet_position.second = position.y;
}
void Bullet::follow_enemy()
{
    pair<double, double> enemy_position = enemy_to_fire->get_enemy_position();
    if(bullet_position.first < enemy_position.first)
    {
        bullet_position.first += BULLET_DELTA_X;
        if(bullet_position.first > enemy_position.first)
            bullet_position.first = enemy_position.first;
    }
    if(bullet_position.first > enemy_position.first)
    {
        bullet_position.first -= BULLET_DELTA_X;
        if(bullet_position.first < enemy_position.first)
            bullet_position.first = enemy_position.first;
    }

    if(bullet_position.second < enemy_position.second)
    {
        bullet_position.second += BULLET_DELTA_X;
        if(bullet_position.second > enemy_position.second)
            bullet_position.second = enemy_position.second;
    }
    if(bullet_position.second > enemy_position.second)
    {
        bullet_position.second -= BULLET_DELTA_X;
        if(bullet_position.second < enemy_position.second)
            bullet_position.second = enemy_position.second;
    }
}
void Bullet::draw_gattling_bullet(Window* window)
{
    follow_enemy();
    window->fill_circle(Point(bullet_position.first, bullet_position.second), BULLET_SIZE, BULLET_COLOR);
}
void Bullet::draw_missile_bullet(Window* window)
{
    follow_enemy();
    window->draw_img("finish.png",Rectangle(bullet_position.first,bullet_position.second,20,7));
}
void Bullet::draw_tesla_bullet(Window* window)
{
    follow_enemy();
    window->draw_img("minw.png",Rectangle(bullet_position.first,bullet_position.second,7,7));
}
void Bullet::draw_glue_bullet(Window* window)
{
    follow_enemy();
    window->draw_img("yellow.png", Rectangle(bullet_position.first, bullet_position.second,20,20));
}
void Bullet::clear_bullet(Window* window)
{
    bullet_position.first = -100;
    bullet_position.second = -100;
}
