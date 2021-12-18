//
// Created by Sridhar Reddy on 12/18/21.
//
#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

Game::Game(int _width, int _height, const char* title) {
    width = _width;
    height = _height;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL)
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}


void Game::StartDraw() {
    TTF_Init();
}

void Game::Write(float _x, float _y, const char* text, TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, text, textColor);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Delay(10); // Fixes crash by making sure the texture is loaded before drawing
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = _x;
    dst.y = _y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
}


void Game::Clear() {
    SDL_SetRenderDrawColor(renderer, 0, 191, 145, 0.8);
    SDL_RenderClear(renderer);
}


void Game::Stop() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}