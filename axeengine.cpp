#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow             = NULL;
SDL_Surface* gScreenSurface     = NULL;
SDL_Surface* gXOut              = NULL;


bool init(){

    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cout << "Could not initialize video!\n"\
                  << SDL_GetError() \
                  << std::endl;
    } else {
        gWindow = SDL_CreateWindow("AxeEngine", \
                                   SDL_WINDOWPOS_UNDEFINED, \
                                   SDL_WINDOWPOS_UNDEFINED, \
                                   SCREEN_WIDTH, \
                                   SCREEN_HEIGHT, \
                                   SDL_WINDOW_SHOWN);
        if(gWindow == NULL){
            std::cout << "Could not create window!\n" << SDL_GetError();
            success = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia(){
    bool success = true;

    gXOut = SDL_LoadBMP("x.bmp");
    if(gXOut == NULL){
        std::cout << "Could not load image!\n" << SDL_GetError();
        success = false;
    }
    return success;
}

void close(){

    SDL_FreeSurface(gXOut);
    gXOut = NULL;

    SDL_FreeSurface(gScreenSurface);
    gScreenSurface = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

//    SDL_Quit();
}

int main() {

    if(!init()){
        std::cout << "Could not initialize!" << std::endl;
    } else {

        if(!loadMedia()){
            std::cout << "Could not load media!" << std::endl;
        } else {
            bool quit = false;

            SDL_Event e;

            while(!quit){
                while(SDL_PollEvent(&e) != 0){
                    if(e.type == SDL_QUIT)
                        quit = true;
                    if(e.type == SDL_KEYDOWN){
                        if(e.key.keysym.sym == SDLK_x)
                            quit = true;
                    }
                }

                SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);

                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }
    close();
    return 0;
}
