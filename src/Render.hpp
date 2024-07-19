#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL_render.h>
#include <SDL_video.h>
#include <vector>
#include "GameObject.hpp"

struct Renderer{
    private:
        SDL_Renderer* renderer;
    public:
        Renderer(SDL_Window* window): renderer { SDL_CreateRenderer(window, -1, 0) } { }

        operator SDL_Renderer*&(){  //return renderer to the name
            return renderer;
        }
        
        void operator=(const Texture& two) = delete;   //copy assignment
        Texture& operator=(Texture&& two) noexcept = delete;   //move assignment

        inline int clear(){
            return SDL_RenderClear(renderer);
        }
        inline void present(){
            SDL_RenderPresent(renderer);
        }
        inline int setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
            return SDL_SetRenderDrawColor(renderer, r, g, b, a);
        }
        inline int setScale(float scaleX, float scaleY ){
            return SDL_RenderSetScale(renderer, scaleX, scaleY);
        }
        inline int drawPoint(int x, int y){
            return SDL_RenderDrawPoint(renderer,x,y);
        }
        inline int drawPoints(std::vector<SDL_Point> points){
            return SDL_RenderDrawPoints(renderer, &points[0], points.size());
        }
        inline int drawLine(int x1, int x2, int y1, int y2){
            return SDL_RenderDrawLine(renderer, x1, x2, y1, y2);
        }
        inline int drawLines(std::vector<SDL_Point>& points){
            return SDL_RenderDrawLines(renderer, &points[0], points.size());
        }
        
        inline int copy(GameObject<WithTexture::YES>& obj){
            return SDL_RenderCopyF(renderer, obj.texture, &obj.src, &obj.dest);
        }
        inline void copy(RepeatedGameObject<CommonSource::YES>& obj){
            for( const auto& elementDest : obj.dest)
                SDL_RenderCopyF(renderer, obj.texture, &obj.src, &elementDest);
        }
        inline void copy(RepeatedGameObject<CommonSource::NO>& obj){
            for( const auto& element : obj.gameObjects)
                SDL_RenderCopyF(renderer, obj.texture, &element.src, &element.dest);
        }
        inline int copy(SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_FRect *dstrect){
            return SDL_RenderCopyF(renderer, texture, srcrect, dstrect);
        }
        //x and y are the orgin of rotation
        //and need to add others to work for repeated objects too
        
        //angle is in degrees
        inline int copyEx(GameObject<WithTexture::YES>& obj, double angle, float x, float y, SDL_RendererFlip flip ){
            SDL_FPoint pt{x,y};
            return SDL_RenderCopyExF(renderer, obj.texture, &obj.src, &obj.dest, angle, &pt, flip);
        }
        
        inline int copyEx( SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_FRect *dstrect, double angle, const SDL_FPoint *center, SDL_RendererFlip flip ){
            return SDL_RenderCopyExF(renderer, texture, srcrect, dstrect, angle, center, flip);
        }
        
        ~Renderer(){    SDL_DestroyRenderer(renderer); }
};

#endif