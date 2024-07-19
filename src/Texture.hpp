#ifndef TEXTURE_ENVELOPE
#define TEXTURE_ENVELOPE

#include <SDL_render.h>

struct Texture{ // Wrapper for SDL_Texture
    private:
        SDL_Texture* texture;
    public:
        Texture(const char* title, SDL_Renderer* renderer);
        Texture& operator=(Texture& two) noexcept;   //copy assignment turned into switch assignment

        Texture& operator=(Texture&& two) noexcept;   //move assignment

        inline operator SDL_Texture*() const{ //returns to the name, let's hope all the const make it immutable
            return texture;
        }

        ~Texture();
};//we've secured that no memory leaks will happen

#endif