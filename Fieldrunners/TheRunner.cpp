#include <iostream>
#include <vector>

#include "TheRunner.hpp"

using namespace std;

void TheRunner::draw(Window* window)
{
    if(under_glue_bullet == 1)
        slow_mo_duration++;
        
    if(direction == 'N')
        window->draw_img("rup.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 35, 35));
    
    if(direction == 'S')
        window->draw_img("rdown.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 35, 35));
        
    if(direction == 'E')
        window->draw_img("rright.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
    
    if(direction == 'W')
        window->draw_img("rleft.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
}