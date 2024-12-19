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

void input() {
    SDL_Event event;

    switch (event.type) {
        case SDL_KEYUP:
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE
            }
            break;
    }

}

void render() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    SDL_GL_SwapBuffers( );
}

void update(float* delta) {

}

int main() {
    bool running;
    float delta;
    static float angle = 0.0f;
    running = init();

    while (running) {
        input();
        render();
        update(&delta);
    }
    return 0;
}