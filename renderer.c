#include <stdio.h>
#include "renderer.h"

#include <SDL2/SDL.h>

Renderer::Renderer(SDL_Window& window, unsigned int width, unsigned int height)
{
    Uint32 rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    gSdlRenderer = SDL_CreateRenderer(&window, -1, rendererFlags);
    if (!gSdlRenderer)
    {
        fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(gSdlRenderer);
}

void Renderer::Clear()
{
    SDL_SetRenderDrawColor(gSdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gSdlRenderer);
}

void Renderer::Present()
{
    SDL_RenderPresent(gSdlRenderer);
}
