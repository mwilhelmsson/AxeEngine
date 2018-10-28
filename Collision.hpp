#ifndef __COLLISION_H_
#define __COLLISION_H_
#include <SDL2/SDL.h>

class Collision {

    public:
        static bool AABB(const SDL_Rect rectA, const SDL_Rect rectB);
};

#endif // __COLLISION_H_
