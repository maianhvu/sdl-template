#include <iostream>
#include <SDL.h>
//#include <SDL_image.h>
#include "sdl_utils.h"
//#include "sdl_image_utils.h"
#include "res_path.h"
#include "cleanup.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv) {
    // Initialize
    if (!init(SDL_INIT_EVERYTHING)) { // || !initIMG(IMG_INIT_PNG)) {
        // IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Create window
    SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        logSDLError(std::cout, "CreateWindow");
        // IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        logSDLError(std::cout, "CreateRenderer");
        cleanup(window);
        // IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Loop and check for events
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;
            if (e.type == SDL_KEYDOWN)
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
                }
        }
        SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    // IMG_Quit();
    SDL_Quit();
    return 0;
}
