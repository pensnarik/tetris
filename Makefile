CC=g++
TARGET=tetris
CFLAGS=-std=c++0x -I. `sdl2-config --cflags` `pkg-config libpng --cflags` -pedantic -Wall
LDFLAGS=`sdl2-config --libs` `pkg-config libpng --libs` -lSDL2_image

all: clean $(TARGET)

$(TARGET): main.o renderer.o app.o game.o
	$(CC) -o $(TARGET) *.o $(LDFLAGS)

main.o: main.c
	$(CC) -c $(CFLAGS) main.c -o main.o

renderer.o: renderer.c
	$(CC) -c $(CFLAGS) renderer.c -o renderer.o

app.o: app.cpp
	$(CC) -c $(CFLAGS) app.cpp -o app.o

game.o: game.cpp
	$(CC) -c $(CFLAGS) game.cpp -o game.o

clean:
	rm -rf *.o
