#ifndef TEXTURE_ENVELOPE
#define TEXTURE_ENVELOPE

#define SDL_MAIN_HANDLED
#include <SDL_render.h>

struct Texture{
        SDL_Texture* texture;

        void operator=(Texture two){
            SDL_DestroyTexture(texture);
            texture = two.texture;
        }
        void operator=(SDL_Texture* two){
            SDL_DestroyTexture(texture);
            texture = two;
        }
        void set(SDL_Texture* two){                 //only used when we are maybe setting from an array, and don't need to destroy the original texture
            texture = two;
        }

        inline SDL_Texture*& operator()(){
            return texture;
        }

        Texture(const char* title, SDL_Renderer* renderer);
        
        inline bool isValid(){ 
            return texture != 0;
        }

        ~Texture();
};

#endif