#ifndef CLEANUP_H
#define CLEANUP_H

#include <utility>
#include <SDL.h>

template<typename T, typename... Args>
void cleanup(T *t, Args&&... args) {
    cleanup(t);
    cleanup(std::forward<Args>(args)...);
}
// Clean up window
template<>
void cleanup<SDL_Window>(SDL_Window *win) {
    if (!win) {
        return;
    }
    SDL_DestroyWindow(win);
}
// Clean up renderer
template<>
void cleanup<SDL_Renderer>(SDL_Renderer *ren) {
    if (!ren) {
        return;
    }
    SDL_DestroyRenderer(ren);
}
// Clean up texture
template<>
void cleanup<SDL_Texture>(SDL_Texture *tex) {
    if (!tex) {
        return;
    }
    SDL_DestroyTexture(tex);
}
// Free surface
template<>
void cleanup<SDL_Surface>(SDL_Surface *surf) {
    if (!surf) {
        return;
    }
    SDL_FreeSurface(surf);
}

#endif
