#include "Rain.hpp"
#include <random>
#include <time.h>

using Random = std::subtract_with_carry_engine<unsigned int,11,7,11>;

namespace Rain{
    RepeatedGameObject<CommonSource::YES> initRain(const char* title, SDL_Renderer* renderer, unsigned int number, int RES_X, int RES_Y){
        std::vector<SDL_FPoint> points (3072);
        Random rand((unsigned) time(nullptr));
        for(auto& drop : points){
            drop.x = rand() % RES_X;
            drop.y = rand() % RES_Y;
            drop.y -= 700;
        }
        return RepeatedGameObject<CommonSource::YES>{ title, renderer, std::move(points) };;
    }
};