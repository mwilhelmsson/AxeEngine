#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

int main() {
    SDL_Window* window = NULL;

    SDL_Surface* surface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Could not initialize!" << std::endl;
    }
    else
    {
        window = SDL_CreateWindow("AxeEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL){
            std::cout << "FEL!";
        }
        else
        {
            surface = SDL_GetWindowSurface(window);
            std::cout << surface << std::endl;
            std::cout << SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(20000);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
