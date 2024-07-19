#include "Texture.hpp"
#include <SDL_image.h>

Texture::Texture(const char* title, SDL_Renderer* renderer){
    SDL_Surface* tempSurface = IMG_Load(title);
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

Texture::~Texture(){
    if(texture != NULL)
        SDL_DestroyTexture(texture);
}

Texture& Texture::operator=(Texture& two) noexcept{
    std::swap(this->texture, two.texture);
    return *this;
}

Texture& Texture::operator=(Texture&& two) noexcept{   //move assignment
    SDL_DestroyTexture(texture);
    texture = two.texture;
    return *this;
}