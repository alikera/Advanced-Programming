#ifndef STUBBORN_RUNNER_HPP
#define STUBBORN_RUNNER_HPP
#define STUBBORN_SPEED 1.5

#include "Enemy.hpp"

class StubbornRunner : public Enemy
{
public:
    StubbornRunner(double health_, int hurt_, double movement_speed_, int killing_reward_, Point start_point) 
        : Enemy(health_, hurt_, movement_speed_, killing_reward_, start_point) {};
    void draw(Window* window);
    void set_movement_speed() { movement_speed = STUBBORN_SPEED; }
};

#endif