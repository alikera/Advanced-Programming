#ifndef SCRAMBLER_HPP
#define SCRAMBLER_HPP
#define SCRAMBLER_SPEED 4.5

#include "Enemy.hpp"

class Scrambler : public Enemy
{
public:
    Scrambler(double health_, int hurt_, double movement_speed_, int killing_reward_, Point start_point) 
        : Enemy(health_, hurt_, movement_speed_, killing_reward_, start_point) {};
    void draw(Window* window);
    void set_movement_speed() { movement_speed = SCRAMBLER_SPEED; }
};

#endif