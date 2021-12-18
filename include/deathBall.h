#ifndef DARKBALL_DEATHBALL_H
#define DARKBALL_DEATHBALL_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDl2/SDL_image.h>

class DeathBall {
public:
    int x;
    int y;
    int w;
    int h;
    bool shouldKill = false;
    int ticks = 140;

    DeathBall(int _x, int _y);
    void Render(SDL_Renderer *renderer);
    void HandleClick(SDL_MouseButtonEvent* event);
    void Move(int g_x, int g_y);
};

#endif //DARKBALL_DEATHBALL_H
