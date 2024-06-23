#include "Rain.hpp"
#include <random>
#include <time.h>
#include <iostream>

using Random = std::subtract_with_carry_engine<unsigned int,11,7,11>;

RepeatedGameObjects Rain::initRain(const char* title, SDL_Renderer* renderer, unsigned int number, int RES_X, int RES_Y){
    RepeatedGameObjects rain{ title, renderer, number };
    Random rand((unsigned) time(nullptr));
    auto base = rain.src;          //we get a copy, so the original source isn't touched
    for(auto& drop : rain.dest){
        drop.x = rand() % RES_X;
        drop.y = rand() % RES_Y;
        drop.y -= 700;
        drop.w = base.w;
        drop.h = base.h;
    }
    return rain;
}