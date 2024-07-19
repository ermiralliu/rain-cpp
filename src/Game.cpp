#include "Game.hpp"
#include <functional>
#include "windowManagement.hpp"
#include <thread>
#include <iostream>
#define SDL_MAIN_HANDLED


Game::Game(const char* title, int X_POS, int Y_POS, int WIDTH, int HEIGHT, Uint32 flags): 
    window{ SDL_CreateWindow(title, X_POS, Y_POS, WIDTH, HEIGHT, flags) } ,
    renderer{ window } ,
    background{ "assets/sky1.png", renderer()},
    rain{ Rain::initRain("assets/snow.png", renderer(), 3072, WIDTH, HEIGHT) }    
    {                                               //this is where the function body is
        
        renderer.setDrawColor(0, 0, 0, 255);
        renderer.clear();
        if(window!=0 && renderer.isValid()){
            isRunning = true;               //so this is what stops the program if the Initialization is Unsuccessful
            exeToForeground("Animations");
        }            
        else
            std::cerr<<"Error in initializing the Window";
    }; 

Game::Game(const char* title, int WIDTH, int HEIGHT): Game(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0){} // {} in the end are for you know what

Game::~Game(){
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout<<"\ncleaned\n";
}

void change(int& number, int min, int max, const char* min_message, const char* max_message){
    std::cout<<"Please enter a value:\n";
    int next;
    std::cin>>next;
    while(next > max || next <min){
        if(next > max)
            std::cout<<max_message<<'\n';
        else
            std::cout<<min_message<<'\n';
        std::cin>>next;
    }
    number = next;
    exeToForeground("Animations");
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button){
                case SDL_BUTTON_LEFT:
                    SDL_GetMouseState(&first.x, &first.y);
                    activeMouse = !activeMouse;
                    break;
            }
            break;
        case SDL_MOUSEMOTION:
                if(!activeMouse)
                    break;
                int x,y;
                SDL_GetMouseState(&x, &y);
                speed.x = (x - first.x)/50;
                speed.y = (y- first.y)/50;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    isRunning =false;
                    return;
                case SDLK_r:{
                    showConsole();
                    //finished = std::async(std::launch::async, change, std::ref(speed.y), 0, 20, "too small", "too big");
                    std::thread (change, std::ref(speed.y), 0, 20, "too small", "too big").detach();
                    //supposedly you should never use detach, but tf esle am I supposed to do in this case
                    break;
                }
                case SDLK_e:{
                    showConsole();
                    //finished = std::async(std::launch::async, change, std::ref(speed.x), -20, 20, "too small", "too big");
                    std::thread (change, std::ref(speed.x), -20, 20, "too small", "too big").detach();
                    break;
                }
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::update(){
    for(auto& drop : rain.dest){
        if(drop.y > 720)
            drop.y = 0;
        else if(drop.y < -800)
            drop.y = 720;
        if(drop.x > 1280)
            drop.x = 0;
        else if(drop.x <0)
            drop.x = 1280;
        drop.x+= speed.x;
        drop.y+= speed.y;
    }
}

void Game::render(){
    //renderer.setDrawColor(0, 0, 0, 255);      //cause not necessary
    renderer.clear();
    //here we show the textures:
    background.show(renderer());
    rain.show( renderer() );          //it cleans out far more arguments if we have renderer as an argument and texture as an object
    //present:
    renderer.present();
}
