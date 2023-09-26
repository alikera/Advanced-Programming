#ifndef THE_RUNNER_HPP
#define THE_RUNNER_HPP
#define THE_RUNNER_SPEED 2.5

#include "Enemy.hpp"

class TheRunner : public Enemy
{
public:
    TheRunner(double health_, int hurt_, double movement_speed_, int killing_reward_, Point start_point) 
        : Enemy(health_, hurt_, movement_speed_, killing_reward_, start_point) {};
	void draw(Window* window);
	void set_movement_speed() { movement_speed = THE_RUNNER_SPEED; }
};

#endif