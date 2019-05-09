#ifndef RENDERER_H
#define RENDERER_H

struct SDL_Window;
struct SDL_Renderer;

class Renderer
{
public:
    Renderer(SDL_Window& window, unsigned int width, unsigned int height);
    ~Renderer();

    void Clear();
    void Present();
private:
    SDL_Renderer* gSdlRenderer;
};

#endif
