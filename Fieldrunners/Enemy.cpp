#include <iostream>
#include <vector>

#include "Enemy.hpp"

using namespace std;
void Enemy::move(path_t enemy_path)
{
	for (int i = 0; i < enemy_path.size(); i += 2)
	{
		if (enemy_position.first == enemy_path[i] && enemy_position.second == enemy_path[i+1] && i > covered_distance)
		{
		    dest_x = enemy_path[i + 2];
		    dest_y = enemy_path[i + 3];
		    covered_distance = i;
		}
		if (enemy_position.first == dest_x && enemy_position.second < dest_y)
		{
			enemy_position.second += movement_speed;
			direction = 'S';
			if (enemy_position.second > dest_y)
				enemy_position.second = dest_y;
			return;
		}
		if (enemy_position.second == dest_y && enemy_position.first < dest_x)
		{
			enemy_position.first += movement_speed;
			direction = 'E';
			if (enemy_position.first > dest_x)
				enemy_position.first = dest_x;
			return;
		}
		if (enemy_position.first == dest_x && enemy_position.second > dest_y)
		{
			enemy_position.second -= movement_speed;
			direction = 'N';
			if (enemy_position.second < dest_y)
				enemy_position.second = dest_y;
			return;
		}
		if (enemy_position.second == dest_y && enemy_position.first > dest_x)
		{
			enemy_position.first -= movement_speed;
			direction = 'W';
			if (enemy_position.first < dest_x)
				enemy_position.first = dest_x;
			return;
		}
	}
}
void Enemy::decrease_movement_speed(int decrease, int slow_mo_power)
{ 
    movement_speed = movement_speed * decrease / 100;
    under_glue_bullet = 1;
    max_duration = slow_mo_power;
} 
bool Enemy::slow_mo_duration_is_over()
{
    if(slow_mo_duration >= max_duration)
    {
        under_glue_bullet = 0;
        slow_mo_duration = 0;
        set_movement_speed();
        return true;
    }
    else
        return false;
}