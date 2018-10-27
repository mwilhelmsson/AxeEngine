#include <iostream>
#include <SDL2/SDL.h>
#include "game.hpp"

Game *game = nullptr;

int main(int argc, char *argv[]) {

    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("AxeEngine",\
               SDL_WINDOWPOS_CENTERED, \
               SDL_WINDOWPOS_CENTERED, \
               800, \
               640, \
               false);
    while(game->running()){

        frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();

    return 0;
}
