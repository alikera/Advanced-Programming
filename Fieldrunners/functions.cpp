#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <time.h>
#include "functions.hpp"
#include "rsdl.hpp"
using namespace std;
double calculate_enemy_health_in_wave(int initial_health, int wave_num)
{
    return (0.9 + 0.1 * wave_num) * initial_health;
}
void get_enemy_path(path_t &enemy_path)
{
    int x;
    while(cin >> x)
    {
        enemy_path.push_back(x);
        if(cin.get() == '\n')
            break;
    }
}
void get_enemies_count_in_each_wave(waves_t &waves)
{
    int x;
    vector<int> wave;
    while(cin >> x)
    {
        wave.push_back(x);
        if(cin.get() == '\n')
        {
            waves.push_back(wave);
            wave.clear();
        }
    }
}
void get_input(path_t &enemy_path, waves_t &waves)
{
    get_enemy_path(enemy_path);
    get_enemies_count_in_each_wave(waves);
}
void create_path_in_pixels(path_t &enemy_path)
{
    for(int i = 0; i < enemy_path.size(); i += 2)
    {
        enemy_path[i] = (enemy_path[i] * 60) + 150;
        enemy_path[i + 1] = (enemy_path[i + 1] * 60) + 205;
    }
}
int calculate_enemy_distance(pair<double, double> enemy, Point tower)
{
    return abs(enemy.first - tower.x) * abs(enemy.first - tower.x) + abs(enemy.second - tower.y) * abs(enemy.second - tower.y);
}