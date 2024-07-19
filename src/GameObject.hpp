#ifndef GAME_OBJE
#define GAME_OBJE

#include "Texture.hpp"
#include <vector>

enum class Choice{
    YES,
    NO
};

using WithTexture = Choice;

template<WithTexture = WithTexture::YES> struct GameObject;

template<> struct GameObject<WithTexture::NO>{   
//this is so you can construct many objects and use a common texture
//but have different sources and destinations for each
    SDL_Rect src{0,0};
    SDL_FRect dest;
    GameObject(){}
    void init(SDL_Texture* text){
        SDL_QueryTexture(text, nullptr, nullptr, &src.w, &src.h);
        dest = {0.0, 0.0, (float) src.w, (float) src.h};
    }
    ~GameObject(){}
};

template<> struct GameObject<WithTexture::YES> : GameObject<WithTexture::NO>{
    Texture texture;
    GameObject(const char* title, SDL_Renderer* renderer): texture{ title, renderer } {
        init(texture);
    }
};

using CommonSource = WithTexture;

template <CommonSource = CommonSource::YES > struct RepeatedGameObject;

template<> struct RepeatedGameObject<CommonSource::YES>{
    Texture texture;
    SDL_Rect src{0,0};
    std::vector<SDL_FRect> dest;
    
    RepeatedGameObject(const char* title, SDL_Renderer* renderer, std::vector<SDL_FPoint>&& destInitializer): texture{ title, renderer }{
        SDL_QueryTexture( texture, nullptr, nullptr, &src.w, &src.h);
        for(const auto& element : destInitializer)
            dest.push_back( {element.x, element.y, (float) src.w, (float) src.h} );
    }
    ~RepeatedGameObject(){}
};

template<> struct RepeatedGameObject<CommonSource::NO>{
    Texture texture;
    std::vector<GameObject<WithTexture::NO>> gameObjects;   //it's probably necessary to mention 
    //arguments on top of fields and function declarations 
};

#endif