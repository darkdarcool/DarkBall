//
// Created by Sridhar Reddy on 12/18/21.
//

#ifndef DARKBALL_GAME_H
#define DARKBALL_GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>

class Game {
public:
    int width;
    int height;
    SDL_Renderer *renderer;
    SDL_Window* window;
    SDL_Surface* surface;
    Game(int _width, int _height, const char* title);
    void Clear();
    void Write(float _x, float _y, const char* text, TTF_Font* font, SDL_Color textColor);
    void Draw();
    void Stop();
    void StartDraw();
};

#endif //DARKBALL_GAME_H
