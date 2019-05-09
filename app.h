#ifndef APP_H
#define APP_H

struct SDL_Window;
class Renderer;

class App
{
public:
    App();

    bool Init();
    void Close();
    void Run();
private:
    SDL_Window* gWindow;
    Renderer* gRenderer;
    const int SCREEN_WIDTH = 400;
    const int SCREEN_HEIGHT = 800;
};

#endif
