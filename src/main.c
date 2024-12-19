#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <stdbool.h>

#define WIN_W 1280
#define WIN_H 720


int init(SDL_GLContext* mainContext, SDL_Window** win) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		perror("unable to init SDL");
		return false;
	}
	int bpp = 0;
	//const SDL_VideoInfo* info = NULL;
	//info = SDL_GetVideoInfo();
	/*if (!info) {
	perror("video query failed");
	return false;
	}
	bpp = info->vfmt->BitsPerPixel;*/


	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	/*if (SDL_SetVideoMode(WIN_W, WIN_H, bpp, SDL_OPENGL) == 0) {
	perror("failed to set video mode");
	return false;
	}*/

	*win = SDL_CreateWindow(
			"SDL OpenGL",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WIN_W,WIN_H,
			SDL_WINDOW_OPENGL
			);
	if (!win) {
		perror("window is NULL");
		return false;
	}

	*mainContext = SDL_GL_CreateContext(*win);


	return true;
}

void input(bool* running) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				*running = false;
				printf("break\n");
				break;
			case SDL_KEYUP:
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						*running = false;
						break;
			    }
			    break;
		}
	}

}

void render(SDL_Window* win) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	SDL_GL_SwapWindow(win);
}

void update(float* delta) {

}

void destroy(SDL_Window* win) {
	SDL_DestroyWindow(win);
	SDL_Quit();
}

int main() {
	SDL_Window* win;
	SDL_GLContext mainContext;
	bool running;
	float delta;
	static float angle = 0.0f;
	running = init(&mainContext, &win);

	while (running) {
		input(&running);
		render(win);
		update(&delta);
	}
	destroy(win);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
