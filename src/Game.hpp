#ifndef GAME_hpp
#define GAME_hpp

#include <SDL.h>
#include "Render.hpp"
#include "Rain.hpp"
#include "GameObject.hpp"
//#include <future>

using vector_2D = SDL_Point;

class Game{
    private:
        SDL_Window* window;
        Renderer renderer;
        GameObject<WithTexture::YES> background;
        bool isRunning;
        bool taskFinished{false};
        vector_2D speed{0,4};
        vector_2D first;
        bool activeMouse{false};    
        //std::future<void> finished;                 //doesn't hold a value but it is necessary to keep the async process going
    
    public:
        RepeatedGameObject<CommonSource::YES> rain;
        Game(const char* title, int X_POS, int Y_POS, int WIDTH, int HEIGHT, Uint32 flags);
        Game(const char* title, int WIDTH, int HEIGHT);
        ~Game();

        void handleEvents();
        void update();
        void render();
        
        inline bool running(){return isRunning;};
        
};

#endif