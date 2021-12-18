#ifndef DARKBALL_GOODBALL_H
#define DARKBALL_GOODBALL_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDl2/SDL_image.h>

class GoodBall {
public:
    int x;
    int y;
    int w;
    int h;
    Uint32 timeout = SDL_GetTicks() + 10;
    bool addPoint = false;

    GoodBall(int _x, int _y);

    void Render(SDL_Renderer *renderer);

    void HandleClick(SDL_MouseButtonEvent *event);

    void Move();
};

#endif //DARKBALL_GOODBALL_H
