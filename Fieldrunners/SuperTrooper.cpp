#include <iostream>
#include <vector>

#include "SuperTrooper.hpp"

using namespace std;

void SuperTrooper::draw(Window* window)
{
    if(under_glue_bullet == 1)
        slow_mo_duration++;
        
    if(direction == 'N')
        window->draw_img("Hup.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
    
    if(direction == 'S')
        window->draw_img("Hdown.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
        
    if(direction == 'E')
        window->draw_img("Hright.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
    
    if(direction == 'W')
        window->draw_img("Hleft.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
}