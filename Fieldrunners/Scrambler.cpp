#include <iostream>
#include <vector>

#include "Scrambler.hpp"
using namespace std;

void Scrambler::draw(Window* window)
{
    if(under_glue_bullet == 1)
        slow_mo_duration++;
        
    if(direction == 'N')
        window->draw_img("bup.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 33, 37));
    
    if(direction == 'S')
        window->draw_img("bdown.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 33, 37));
        
    if(direction == 'E')
        window->draw_img("bright.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
    
    if(direction == 'W')
        window->draw_img("bleft.png", Rectangle(enemy_position.first - 20, enemy_position.second - 20, 40, 40));
}