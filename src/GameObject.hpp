#ifndef GAME_OBJE
#define GAME_OBJE

#include "Texture.hpp"

struct GameObject{
    Texture texture;
    SDL_Rect src{0,0};
    SDL_FRect dest;

    GameObject(const char* title, SDL_Renderer* renderer): texture{ title, renderer } {
        SDL_QueryTexture(texture(), nullptr, nullptr, &src.w, &src.h);
        dest = {0.0, 0.0, (float) src.w, (float) src.h};
    }

    inline int show(SDL_Renderer* renderer){
        return SDL_RenderCopyF(renderer, texture(), &src, &dest);
    }
    
    ~GameObject(){}
};

#endif