#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

Map* map;

GameObject* player;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, \
                int xpos, \
                int ypos, \
                int width, \
                int height, \
                bool fullscreen) {

    int flags = 0;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Initialized everything" << std::endl;
        if (fullscreen)
            flags = SDL_WINDOW_FULLSCREEN;

        window = SDL_CreateWindow(title, \
                                  xpos, \
                                  ypos, \
                                  width, \
                                  height, \
                                  flags);
        if(window)
            std::cout << "Window created!" << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    player = new GameObject("assets/ugly.png",0,0);
    map = new Map();
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update(){
    player->Update();
}

void Game::render(){
    SDL_RenderClear(renderer);

    //add stuff to render
    map->DrawMap();
    player->Render();

    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
