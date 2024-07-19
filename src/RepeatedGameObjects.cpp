#include "RepeatedGameObjects.hpp"
#include <SDL_image.h>
#include <algorithm>


SDL_Rect src_init(SDL_Texture* texture){
    SDL_Rect src{0,0};
    SDL_QueryTexture(texture, nullptr, nullptr, &src.w, &src.h);
    return src;
}

RepeatedGameObjects::RepeatedGameObjects(const char* title, SDL_Renderer*& renderer, unsigned int size):
    texture{ title, renderer },
    src{ src_init(texture())},
    dest{ size }                                                                                    //size of dest vector
{ }

void RepeatedGameObjects::addElement(float x, float y, float w, float h){
    dest.push_back({x,y,w,h});
}

void RepeatedGameObjects::addElement(float x, float y){
    dest.push_back({x, y, (float) src.w, (float) src.h});
}

void RepeatedGameObjects::addElement(float x, float y, float scale){
    dest.push_back({x,y, (float) src.w*scale, (float) src.h*scale});
}

void RepeatedGameObjects::changeTexture(SDL_Texture* another, bool getSizes){       //if the other stuff has a different size of the image
    texture = another;
    if(getSizes){
        for(auto& element: dest){
            element.w = src.w;
            element.h = src.h;
        }
    }   
}

void RepeatedGameObjects::sort(){
    std::sort(dest.begin(), dest.end(), [](const SDL_FRect& one, const SDL_FRect& two){         //sorts in ascending order
                                            return one.y > two.y;                               //if two is lower in the screen, it's rendered above the stuff
                                        });                                                     //that is higher in the screen, like in 2D games
}                                                                                               //that have a small 3D feeling  
                                                                                                //where stuff that is higher on the screen is considered further away
                                                                                                //needs to contain every object in the game to actually be fully correct though
                                                                                                //maybe there'll be another vector with pointers to all the objects, where we don't render if the pointer is nullptr