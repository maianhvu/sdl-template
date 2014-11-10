#ifndef SDL_IMAGE_UTILS_H
#define SDL_IMAGE_UTILS_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "sdl_utils.h"

// Load an image as a texture
SDL_Texture *loadIMGTexture(const std::string &file, SDL_Renderer *ren) {
    SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
    if (texture == nullptr) {
        logSDLError(std::cout, "LoadTexture");
    }
    return texture;
}

// Initialize IMG
bool initIMG(int flags) {
    if ((IMG_Init(flags) & flags) != flags) {
        logSDLError(std::cout, "IMG_Init");
        return false;
    }
    return true;
}

#endif
