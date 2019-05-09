#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "app.h"

int main(int argc, char *argv[])
{
    App app;
    if (!app.Init()) {
        printf("Couldn't initialize application");
        app.Close();
        exit(1);
    }
    app.Run();
    app.Close();

    return 0;
}
