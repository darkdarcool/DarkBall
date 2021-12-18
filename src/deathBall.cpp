#include "deathBall.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDl2/SDL_image.h>

DeathBall::DeathBall(int _x, int _y) {
    x = _x;
    y = _y;
    w = 20;
    h = 20;
}

void DeathBall::Render(SDL_Renderer *renderer) {
    SDL_Texture* tex = IMG_LoadTexture(renderer, "./res/sprites/DeathBall.png");
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopy(renderer, tex, NULL, &rect);
}

void DeathBall::HandleClick(SDL_MouseButtonEvent *event) {
    if (event->x > x && event->x < x + w && event->y > y && event->y < y + h) {
        shouldKill = true;
    }
}

void DeathBall::Move(int g_x, int g_y) {
    if (SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
        x = g_x;
        y = g_y;
        timeout = SDL_GetTicks() + 1230;
    }
}