#ifndef __TEXTUREMANAGER_H_
#define __TEXTUREMANAGER_H_
#include "game.hpp"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);

};


#endif // __TEXTUREMANAGER_H_
