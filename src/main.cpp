#include "Game.hpp"
#include <SDL_timer.h>

constexpr const char title[] = "Animations"; //for some reason the template didn't accept it if declared in main
constexpr int RES_X { 1280 };
constexpr int RES_Y { 720 };

constexpr int FRAME_DELAY{ 16 };

int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_EVERYTHING) !=0)   //if the program isn't initialized successfully, exit 1;
        return 1;
    Game game(title, RES_X, RES_Y);

    while(game.running()){
        auto frameStart = SDL_GetTicks();
        game.handleEvents();
        game.update();
        game.render();
        auto frameTime = SDL_GetTicks() - frameStart;
		if(FRAME_DELAY > frameTime)
			SDL_Delay(FRAME_DELAY - frameTime);
    }
    return 0;
}