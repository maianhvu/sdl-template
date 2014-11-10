#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <iostream>
#include <string>
#include <SDL.h>

// Error logging
void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

// initialize
bool init(Uint32 flags) {
    if (SDL_Init(flags) != 0) {
        logSDLError(std::cout, "SDL_Init");
        return false;
    }
    return true;
}

// Loading BMP texture
SDL_Texture* loadBMPTexture(const std::string &file, SDL_Renderer *ren) {
    SDL_Texture *texture = nullptr;
    SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != nullptr) {
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == nullptr) {
            logSDLError(std::cout, "CreateTextureFromSurface");
        }
    } else {
        logSDLError(std::cout, "LoadBMP");
    }
    return texture;
}

// Render a texture with specified width and height
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
        int w, int h) {
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
}
// Render a texture as-is at (x, y)
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    renderTexture(tex,ren,x,y,w,h);
}

#endif
