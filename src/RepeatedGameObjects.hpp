#ifndef REP_GAME_OBJ
#define REP_GAME_OBJ

#include <vector>
#include "Texture.hpp"

struct RepeatedGameObjects{
        Texture texture;
        SDL_Rect src;
        std::vector<SDL_FRect> dest;

        RepeatedGameObjects(const char* title, SDL_Renderer*& renderer, unsigned int size);

        void addElement(float x, float y, float w, float h);
        void addElement(float x, float y);
        void addElement(float x, float y, float scale);
        void changeTexture(SDL_Texture* another, bool getWidth);
       
        inline void show(SDL_Renderer*& renderer){                                                                                                               
                                    //I wanted to have the renderer show the texture, but this takes three arguments out, that would only take out one
            for(auto& instance : dest)
                SDL_RenderCopyF(renderer, texture(), &src, &instance);
        }
        
        void sort();

        ~RepeatedGameObjects(){ };
};

#endif