#define SDL_MAIN_HANDLED
#include "Game.hpp"

constexpr const char title[12] = "Animations"; //for some reason the template didn't accept it if declared in main
constexpr int RES_X { 1280 };
constexpr int RES_Y { 720 };

constexpr int FRAME_DELAY{ 16 };

int main(int argv, char** args){
    if(SDL_Init(SDL_INIT_EVERYTHING) !=0)   //if the program isn't initialized successfully, return 1;
        return 1;

    Game game(title, RES_X, RES_Y);
    //auto& dest = game.rain.dest;
    // auto sth = std::async(std::launch::async, [dest](){
    //                                                     for(const auto& drop: dest)
    //                                                         std::cout<< drop.y<<'\n';
    //                                                     std::cout<<std::endl;
    //                                                     return true;
    //                                                 });
    
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