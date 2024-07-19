#ifndef RAIN_HPP
#define RAIN_HPP

#include "GameObject.hpp"
#include <SDL_render.h>

namespace Rain{
    RepeatedGameObject<CommonSource::YES> initRain(const char* title, SDL_Renderer* renderer, unsigned int number, int RES_X, int RES_Y);
}

#endif