#include <stdio.h>
#include "renderer.h"

#include <SDL2/SDL.h>

static SDL_Color MakeSDL_Color(uint32_t rgba)
{
    SDL_Color color;
    color.r = (unsigned char) (( rgba >> 24 ) & 0xff);
    color.g = (unsigned char) (( rgba >> 16 ) & 0xff);
    color.b = (unsigned char) (( rgba >> 8 ) & 0xff);
    color.a = (unsigned char) (( rgba >> 0 ) & 0xff); // alpha
    return color;
}

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

void Renderer::DrawSolidRect(int x, int y, int w, int h, uint32_t rgba /*= 0xffffffff */)
{
    SDL_Color color = MakeSDL_Color(rgba);
    SDL_SetRenderDrawColor(gSdlRenderer, color.r, color.g, color.b, color.a);

    SDL_Rect rect = { x, y, w, h };
    SDL_RenderFillRect(gSdlRenderer, &rect );
}

void Renderer::DrawRect(int x, int y, int w, int h, uint32_t rgba /*= 0xffffffff */)
{
    SDL_Color color = MakeSDL_Color(rgba);
    SDL_SetRenderDrawColor(gSdlRenderer, color.r, color.g, color.b, color.a);

    SDL_Rect rect = {x, y, w, h};
    SDL_RenderDrawRect(gSdlRenderer, &rect);
}
