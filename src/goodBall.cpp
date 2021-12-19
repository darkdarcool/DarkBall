#include "goodBall.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDl2/SDL_image.h>

GoodBall::GoodBall(int _x, int _y) {
    x = _x;
    y = _y;
    w = 20;
    h = 20;
}

void GoodBall::Render(SDL_Renderer *renderer) {
    SDL_Texture* tex = IMG_LoadTexture(renderer, "./res/sprites/OLDPEOPLEGOODBALL.png");
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopy(renderer, tex, NULL, &rect);
}

void GoodBall::HandleClick(SDL_MouseButtonEvent *event) {
    if (event->x > x && event->x < x + w && event->y > y && event->y < y + h) {
        addPoint = true;

    }
}

void GoodBall::Move() {
    if (SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
        x = rand() % (640 - w);
        y = rand() % (480 - h);
        timeout = SDL_GetTicks() + 900;
    }
}

