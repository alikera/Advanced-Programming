#include <iostream>
#include <vector>

#include "StubbornRunner.hpp"

using namespace std;

void StubbornRunner::draw(Window* window)
{
    if(under_glue_bullet == 1)
        slow_mo_duration++;
        
    if(direction == 'N')
        window->draw_img("iup.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
    
    if(direction == 'S')
        window->draw_img("idown.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
        
    if(direction == 'E')
        window->draw_img("iright.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
    
    if(direction == 'W')
        window->draw_img("ileft.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
}