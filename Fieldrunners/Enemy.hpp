#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <vector>
#include "rsdl.hpp"
typedef std::vector<int> path_t;
class Enemy
{
public:
	Enemy(double health_, int hurt_, double movement_speed_, int killing_reward_, Point start_point)
	{
        health = health_;
        hurt = hurt_;
        movement_speed = movement_speed_;
        killing_reward = killing_reward_;
        enemy_position.first = start_point.x;
        enemy_position.second = start_point.y;
    }
    virtual void draw(Window* window) = 0;
    void set_enemy_position(double _x, double _y) { enemy_position.first = _x; enemy_position.second = _y; }
    std::pair<double, double> get_enemy_position() { return enemy_position; }
    void decrease_movement_speed(int decrease, int slow_mo_power);
    virtual void set_movement_speed() = 0; 
    void set_health(int x) { health += x; }
    double get_health() { return health; }
    int get_hurt() { return hurt; }
    int get_killing_reward() { return killing_reward; }
    int get_created() { return created; }
    void set_created(int i) { created = i; } 
    void move(path_t enemy_path);
    int get_under_glue_bullet() { return under_glue_bullet; }
    bool slow_mo_duration_is_over();
protected:
	std::pair<double, double> enemy_position;
	double health;
	double movement_speed;
	int killing_reward;
	int hurt;
	char direction;
	int created = 0;
	double dest_x;
	double dest_y;
	int covered_distance = -1;
	int under_glue_bullet = 0;
	int slow_mo_duration = 0;
	int max_duration;
};
typedef std::vector<Enemy*> enemies_t;

#endif