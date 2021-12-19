//
// Created by Sridhar Reddy on 12/18/21.
//

#ifndef DARKBALL_ROYALBALL_H
#define DARKBALL_ROYALBALL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RoyalBall {
public:

    RoyalBall();
    int x;
    int y;
    int w;
    int h;
    Uint32 timeout = SDL_GetTicks() + 10;
    bool addPoint = false;

    void Render(SDL_Renderer *renderer);

    void HandleClick(SDL_MouseButtonEvent *event);

    void Move();

    void ResetPos();

    int HitWall();
};


#endif //DARKBALL_ROYALBALL_H
