LIBS = -lSDL2 -lGL
build:
	gcc ./src/main.c $(LIBS) -o test
