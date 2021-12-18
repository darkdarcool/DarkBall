#include <SDL2/SDL.h>
#include "game.h"
#include "deathBall.h"
#include "goodBall.h"
#include <vector>

SDL_Color white = { 255, 255, 255 };
DeathBall dball(50, 50);
GoodBall gball(100, 100);

int main()
{
    Game game(640, 480, "DarkBall");
    game.Clear();

    bool quit = false;
    int splashTime = 0;
    bool keyDown = false;
    bool isIntro = true;
    bool mouseDown = false;
    bool isDead = false;
    int score = 0;
    SDL_Keysym key;
    while (!quit) {
        SDL_Event event;
        SDL_MouseButtonEvent mouse;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                keyDown = true;
                key = event.key.keysym;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                mouse = event.button;
                mouseDown = true;
            }
        }
        game.Clear();
        TTF_Init();
        TTF_Font *cocogoose = TTF_OpenFont("./res/fonts/cocogoose.ttf", 24);
        TTF_Font *title = TTF_OpenFont("./res/fonts/title.ttf", 24);

        if (isIntro) {
            splashTime++;
            if (splashTime < 300) {
                game.Write(220, 200, "darkdarcool", title, white);

            } else {
                game.Write(230, 200, "DarkBall", title, white);
                game.Write(150, 250, "Press any key to start", title, white);
                if (keyDown) {
                    isIntro = false;
                }
            }
        }
        else if (!isDead) {
            game.Write(10, 10, std::string(std::string("Score: ") + std::to_string(score)).c_str(), cocogoose, white);
            dball.Render(game.renderer);
            gball.Render(game.renderer);
            gball.Move();
            dball.Move(gball.x, gball.y);
            if (mouseDown) {
                dball.HandleClick(&mouse);
                gball.HandleClick(&mouse);
                mouseDown = false;
            }
            if (dball.shouldKill) {
                isDead = true;
                dball.shouldKill = false;
            }
            if (gball.addPoint) {
                score++;
                gball.addPoint = false;
            }
        }
        else if (isDead) {
            game.Write(10, 10, std::string(std::string("Score: ") + std::to_string(score)).c_str(), cocogoose, white);
            game.Write(10, 40, "You died!", title, white);
            game.Write(10, 70, "Press any key to restart", title, white);
            if (keyDown) {
                isDead = false;
                score = 0;
                gball = GoodBall(100, 100);
                dball = DeathBall(50, 50);
            }
        }
        SDL_RenderPresent(game.renderer);
        // Cleanup
        keyDown = false;
    }

    // SDL cleanup
    SDL_Quit();
    return 0;
}