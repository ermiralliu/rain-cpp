#include "Texture.hpp"
#include <SDL_image.h>

Texture::Texture(const char* title, SDL_Renderer* renderer){
    SDL_Surface* tempSurface = IMG_Load(title);
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

Texture::~Texture(){
    if(isValid())    
        SDL_DestroyTexture(texture);
}