#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <time.h>
#include "rsdl.hpp"
typedef std::vector<int> path_t;
typedef std::vector<std::vector<int> > waves_t;

double calculate_enemy_health_in_wave(int initial_health, int wave_num);
void get_enemy_path(path_t &enemy_path);
void get_enemies_count_in_each_wave(waves_t &waves);
void get_input(path_t &enemy_path, waves_t &waves);
void create_path_in_pixels(path_t &enemy_path);
int calculate_enemy_distance(std::pair<double, double> enemy, Point tower);
int myrandom (int i) { return rand()%i;}

#endif