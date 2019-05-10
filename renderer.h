#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>

struct SDL_Window;
struct SDL_Renderer;

class Renderer
{
public:
    Renderer(SDL_Window& window, unsigned int width, unsigned int height);
    ~Renderer();

    void Clear();
    void Present();
    void DrawSolidRect(int x, int y, int w, int h, uint32_t rgba);
    void DrawRect(int x, int y, int w, int h, uint32_t rgba);
private:
    SDL_Renderer* gSdlRenderer;
};

#endif
