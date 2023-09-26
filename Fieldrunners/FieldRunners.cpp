#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <time.h>
#define BACKGROUND_NAME "background.png"
#define TOWER_RANGE 150 * 150
#define THE_RUNNER_PATH "runner.png"
#define THE_RUNNER_SPEED 2.5
#define THE_RUNNER_HURT 1
#define THE_RUNNER_KILLING_AWARD 6
#define THE_STUBBORN_PATH "icerunner.png"
#define STUBBORN_SPEED 1.5
#define STUBBORN_HURT 4
#define STUBBORN_KILLING_AWARD 10
#define THE_SCRAMBLER_PATH "biker.png"
#define SCRAMBLER_SPEED 4.5
#define SCRAMBLER_HURT 2
#define SCRAMBLER_KILLING_AWARD 4
#define THE_SUPPERTROOPER_PATH "heavyrunner.png"
#define SUPER_TROOPER_SPEED 1.25
#define SUPPER_TROOPER_HURT 4
#define SUPER_TROOPER_KILLING_AWARD 8
#define GATTLING_BUILD_COST 55
#define GATTLING_KEY 'g'
#define GATTLING_DAMAGE 35
#define GATTLING_UPGRADE_COST 40
#define GATTLING_UPGRADE_DAMAGE_INCREASE 35
#define MISSILE_BUILD_COST 70
#define MISSILE_KEY 'm'
#define MISSILE_DAMAGE 75
#define MISSILE_UPGRADE_COST 60
#define MISSILE_UPGRADE_DAMAGE_INCREASE 75
#define TESLA_BUILD_COST 120
#define TESLA_KEY 't'
#define TESLA_DAMAGE 700
#define TESLA_UPGRADE_COST 100
#define TESLA_UPGRADE_DAMAGE_INCREASE 1000
#define GLUE_BUILD_COST 60
#define GLUE_KEY 'l'
#define GLUE_DAMAGE 40
#define GLUE_UPGRADE_COST 45
#define GLUE_UPGRADE_DAMAGE_INCREASE 10
#define GLUE_UPGRADE_DURATION_INCREASE 10
#define UPGRADE_KEY 'u'
#define BULLET_DELTA_X 15
#define BULLET_SIZE 3
#define BULLET_COLOR BLACK
#include "FieldRunners.hpp"
#include "Gattling.hpp"
#include "Tesla.hpp"
#include "Missile.hpp"
#include "Glue.hpp"
#include "StubbornRunner.hpp"
#include "SuperTrooper.hpp"
#include "TheRunner.hpp"
#include "Scrambler.hpp"
#include "rsdl.hpp"
#include "functions.hpp"

using namespace std;
void FieldRunners::create_enemies(waves_t waves)
{
    if(enemies.size() != 0)
        return;
    srand(time(0));
    vector<int> wave = waves[game_round-1];
    Point start_point;
    start_point.x = -100;
    start_point.y = -100;
    create_the_runner(wave, start_point);
    create_stubborn(wave, start_point);
    create_super_trooper(wave, start_point);
    create_scrambler(wave, start_point);
    random_shuffle(enemies.begin(), enemies.end(), myrandom);
}
void FieldRunners::create_the_runner(vector<int> wave, Point start_point)
{
    double current_health = calculate_enemy_health_in_wave(250, game_round);
    for(int i=0; i < wave[0]; i++)
    {
        TheRunner* the_runner = new TheRunner(current_health, THE_RUNNER_HURT, THE_RUNNER_SPEED, 
                                                THE_RUNNER_KILLING_AWARD,start_point);
        enemies.push_back(the_runner);
    }
}
void FieldRunners::create_stubborn(vector<int> wave, Point start_point)
{
    double current_health = calculate_enemy_health_in_wave(400, game_round);
    for(int i=0; i < wave[1]; i++)
    {
        StubbornRunner* stubborn = new StubbornRunner(current_health, STUBBORN_HURT, STUBBORN_SPEED, 
                                                        STUBBORN_KILLING_AWARD,start_point);
        enemies.push_back(stubborn);
    } 
}
void FieldRunners::create_super_trooper(vector<int> wave, Point start_point)
{
    double current_health = calculate_enemy_health_in_wave(500, game_round);
    for(int i=0; i < wave[2]; i++)
    {
        SuperTrooper* super_trooper = new SuperTrooper(current_health, SUPPER_TROOPER_HURT, SUPER_TROOPER_SPEED, 
                                                        SUPER_TROOPER_KILLING_AWARD,start_point);
        enemies.push_back(super_trooper);
    }
}
void FieldRunners::create_scrambler(vector<int> wave, Point start_point)
{
    double current_health = calculate_enemy_health_in_wave(100, game_round);
    for(int i=0; i < wave[3]; i++)
    {
        Scrambler* scrambler = new Scrambler(current_health, SCRAMBLER_HURT, SCRAMBLER_SPEED, 
                                                SCRAMBLER_KILLING_AWARD,start_point);
        enemies.push_back(scrambler);
    }
}
void FieldRunners::set_enemies_position(int enemy_delay, path_t enemy_path)
{
	for(int i = 0; i < enemies.size(); i++)
	{
		if(enemies[i]->get_created() == 0 && enemy_delay % 10 == 0)
		{
			enemies[i]->set_enemy_position(enemy_path[0], enemy_path[1]);
			enemies[i]->set_created(1);
			break;
		}
	}
}

void FieldRunners::update(Window* window, Point &mouse_p)
{
    if(window->has_pending_event())
    {
        Event event = window->poll_for_event();
        if(event.get_type() == Event::LCLICK)
        {
            mouse_p = event.get_mouse_position();
            set_exact_mouse_position(mouse_p);
        }
            
        if(event.get_type() == Event::KEY_PRESS && mouse_p.x != INVALID)
        {
            char pressed_char = event.get_pressed_key();
            build_towers(window, mouse_p, pressed_char);
            if (pressed_char == UPGRADE_KEY)
                upgrade_tower(mouse_p);
        }
            
        if(event.get_type() == Event::QUIT)
        {
            exit(0);
            return;
        }
    }
}
void FieldRunners::set_exact_mouse_position(Point &mouse_p)
{
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if(abs(mouse_p.x - (i * 60) - 150) <= 30 &&
                abs(mouse_p.y - (j * 60) - 205) <= 30)
            {
                mouse_p.x = (i * 60) + 150;
                mouse_p.y = (j * 60) + 205;
                return;
            }
        }
    }
    mouse_p.x = INVALID;
}
void FieldRunners::build_towers(Window* window, Point &mouse_p, char pressed_char)
{
    if (pressed_char == GATTLING_KEY && user_money - GATTLING_BUILD_COST > 0) 
        build_gattling(window, mouse_p);
        
    if (pressed_char == MISSILE_KEY && user_money - MISSILE_BUILD_COST > 0) 
        build_missile(window, mouse_p);
        
    if (pressed_char == TESLA_KEY && user_money - TESLA_BUILD_COST > 0)
        build_tesla(window, mouse_p);
        
    if (pressed_char == GLUE_KEY && user_money - GLUE_BUILD_COST > 0)
        build_glue(window, mouse_p);
}
void FieldRunners::build_gattling(Window* window, Point &mouse_p)
{
    Gattling* gattling = new Gattling(GATTLING_DAMAGE, GATTLING_UPGRADE_COST);
    gattling->set_tower_position(window, mouse_p);
    towers.push_back(gattling);
    mouse_p.x = INVALID;
    user_money -= GATTLING_BUILD_COST;
}
void FieldRunners::build_missile(Window* window, Point &mouse_p)
{
    Missile* missile = new Missile(MISSILE_DAMAGE, MISSILE_UPGRADE_COST);
    missile->set_tower_position(window, mouse_p);
    towers.push_back(missile);
    mouse_p.x = INVALID;
    user_money -= MISSILE_BUILD_COST;
}
void FieldRunners::build_tesla(Window* window, Point &mouse_p)
{
    Tesla* tesla = new Tesla(TESLA_DAMAGE, TESLA_UPGRADE_COST);
    tesla->set_tower_position(window, mouse_p);
    towers.push_back(tesla);
    mouse_p.x = INVALID;
    user_money -= TESLA_BUILD_COST;
}
void FieldRunners::build_glue(Window* window, Point &mouse_p)
{
    Glue* glue = new Glue(GLUE_DAMAGE, GLUE_UPGRADE_COST);
    glue->set_tower_position(window, mouse_p);
    towers.push_back(glue);
    mouse_p.x = INVALID;
    user_money -= GLUE_BUILD_COST;
}
void FieldRunners::upgrade_tower(Point &mouse_p)
{
    for(int i = 0; i < towers.size(); i++)
	{
        if(towers[i]->tower_is_upgradable(mouse_p) && 
            user_money - towers[i]->get_upgrade_cost() > 0)
		{
			user_money -= towers[i]->get_upgrade_cost();
            towers[i]->set_level();
			towers[i]->upgrade_damage();
			mouse_p.x = INVALID;
			return;
		}
	}
}
void FieldRunners::draw_everything(Window* window, path_t enemy_path)
{
    window->clear();
    window->draw_img(BACKGROUND_NAME, Rectangle(0,0,1365,1024));
    draw_enemies_path(window, enemy_path);
    delete_enemies(enemy_path);
    draw_enemies(window, enemy_path);
    draw_towers(window);
    window->update_screen();
}
void FieldRunners::delete_enemies(path_t enemy_path)
{
    for(int i=0; i < enemies.size(); i++)
    {
        delete_killed_enemies(i);
        delete_survived_enemies(i, enemy_path);
    }
}
void FieldRunners::delete_killed_enemies(int i)
{
    if(enemies[i]->get_health() <= 0)
    {
        user_money += enemies[i]->get_killing_reward();
        delete enemies[i];
        enemies.erase(enemies.begin() + i);
    }
}
void FieldRunners::delete_survived_enemies(int i, path_t enemy_path)
{
    if(enemies[i]->get_enemy_position().first == enemy_path[enemy_path.size() - 2] &&
        enemies[i]->get_enemy_position().second == enemy_path[enemy_path.size() - 1])
    {
        user_hearts -= enemies[i]->get_hurt();
        delete enemies[i];
        enemies.erase(enemies.begin() + i);
    }   
}
void FieldRunners::draw_enemies(Window* window, path_t enemy_path)
{
    for(int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->draw(window);
        enemies[i]->move(enemy_path);
        enemies[i]->slow_mo_duration_is_over();
    }
}
void FieldRunners::draw_towers(Window* window)
{
    for(int i = 0; i < towers.size(); i++)
	{
        towers[i]->draw(window);
        towers[i]->fire_enemy(window, enemies);
	}
}
void FieldRunners::check_for_gome_over(Window* window, waves_t waves)
{
    if(user_hearts <= 0)
    {
        window->draw_img("youlose.png",Rectangle(0,0,1365,1024));
        window->update_screen();
        delay(3000);
        exit(0);
    }
    if(game_round - 1 == waves.size())
    {
        window->draw_img("youwin.png",Rectangle(0,0,1365, 1024));
        window->update_screen();
        delay(3000);
        exit(0);
    }
    // cout<<user_money<<endl;
}
void FieldRunners::game_round_counter()
{
    if(enemies.size() == 0)
    {
        delay(3000);
        game_round++;
    }
}
void FieldRunners::draw_enemies_path(Window* window, path_t enemy_path)
{
    for(int i = 0; i < enemy_path.size() - 2; i += 2)
        window->draw_line(Point(enemy_path[i], enemy_path[i+1]),Point(enemy_path[i+2], enemy_path[i+3]),RED); 
}