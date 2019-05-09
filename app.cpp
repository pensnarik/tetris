#include "app.h"
#include "renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

App::App()
  : gWindow(nullptr)
  , gRenderer(nullptr)
{

}

bool App::Init()
{
    bool success = true;
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {

            //Create renderer for window
            gRenderer = new Renderer(*gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
        }
    }
    return success;
}

void App::Run()
{
    bool quit = false;
    // Event handler
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym)
                {
                    case SDLK_q:
                        Close();
                        break;
                }
            }
            gRenderer->Clear();
            gRenderer->Present();
        }
    }
    Close();
}

void App::Close()
{
    // Destroy window
    SDL_DestroyWindow(gWindow);

    // Quit SDL subsystems
    SDL_Quit();
    exit(0);
}
