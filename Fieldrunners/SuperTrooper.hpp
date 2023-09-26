#ifndef SUPER_TROOPER_HPP
#define SUPER_TROOPER_HPP
#define SUPER_TROOPER_SPEED 1.25

#include "Enemy.hpp"

class SuperTrooper : public Enemy
{
public:
    SuperTrooper(double health_, int hurt_, double movement_speed_, int killing_reward_, Point start_point) 
        : Enemy(health_, hurt_, movement_speed_, killing_reward_, start_point) {};
    void draw(Window* window);
    void set_movement_speed() { movement_speed = SUPER_TROOPER_SPEED; }
};

#endif