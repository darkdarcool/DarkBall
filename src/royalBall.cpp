#include "royalBall.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

RoyalBall::RoyalBall() {
    x = 0;
    y = rand() % (480 - 20);
    w = 20;
    h = 20;
}

void RoyalBall::Render(SDL_Renderer *renderer) {
    SDL_Texture* tex = IMG_LoadTexture(renderer, "./res/sprites/RoyalBall.png");
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopy(renderer, tex, NULL, &rect);
}

void RoyalBall::HandleClick(SDL_MouseButtonEvent *event) {
    if (event->x > x && event->x < x + w && event->y > y && event->y < y + h) {
        addPoint = true;
    }
}

void RoyalBall::Move() {
    x += 10;
}

void RoyalBall::ResetPos() {
    x = 0;
    y = rand() % (480 - 20);
}


int RoyalBall::HitWall() {
    return x > 640;
}