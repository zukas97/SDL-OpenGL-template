#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <gl/glew.h>
#include <gl\glu.h>
#include <stdbool.h>

#define WIN_W 1280
#define WIN_H 720


int init() {
    if (SDL_Init(SDL_INIT_EVERYHING) < 0) {
        perror("unable to init SDL");
        return false;
    }

    int bpp = 0;
    const SDL_VideoInfo* info = NULL;
    info = SDL_GetVideoInfo();
    if (!info) {
        perror("video query failed");
        return false;
    }
    bpp = info->vfmt->BitsPerPixel;
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    if (SDL_SetVideoMode(WIN_W, WIN_H, bpp, SDL_OPENGL) == 0) {
        perror("failed to set video mode");
        return false;
    }

    return true;
}