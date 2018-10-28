#ifndef __GAME_H_
#define __GAME_H_
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>


class Game {
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running(){ return isRunning; };

        static SDL_Renderer *renderer;
        static SDL_Event event;
    private:
        bool isRunning;
        int counter = 0;
        SDL_Window *window;

};

#endif // __GAME_H_
