#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <time.h>
#define BACKGROUND_NAME "background.png"
#define INVALID -1
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
#define MISSILE_BUILD_COST 70
#define MISSILE_KEY 'm'
#define MISSILE_DAMAGE 75
#define MISSILE_UPGRADE_COST 60
#define TESLA_BUILD_COST 120
#define TESLA_KEY 't'
#define TESLA_DAMAGE 700
#define TESLA_UPGRADE_COST 100
#define GLUE_BUILD_COST 60
#define GLUE_KEY 'l'
#define GLUE_DAMAGE 40
#define GLUE_UPGRADE_COST 45
#define UPGRADE_KEY 'u'
#define BULLET_DELTA_X 15
#define BULLET_SIZE 3
#define BULLET_COLOR BLACK
typedef std::vector<int> path_t;
typedef std::vector<std::vector<int> > waves_t;

#include "FieldRunners.hpp"
#include "rsdl.hpp"

using namespace std;

int main()
{
    path_t enemy_path;
    waves_t waves;
    get_input(enemy_path, waves);
    Window *window = new Window(1365, 1024, "RSDL Demo");
    create_path_in_pixels(enemy_path);
    FieldRunners fieldrunners;
    Point mouse_p;
    int enemy_delay = 0;
    while(true)
    {
        fieldrunners.check_for_gome_over(window, waves);
        fieldrunners.create_enemies(waves);
        enemy_delay++;
        fieldrunners.set_enemies_position(enemy_delay, enemy_path);
        fieldrunners.update(window, mouse_p);
        fieldrunners.draw_everything(window, enemy_path);
        fieldrunners.game_round_counter();
        delay(50);
    }
    return 0;
}