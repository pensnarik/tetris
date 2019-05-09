#ifndef GAME_H
#define GAME_H

class Renderer;

struct GameInput
{
    bool bStart;
    bool bMoveLeft;
    bool bMoveRight;
};

class Game
{
public:
    Game();
    ~Game();

    bool Init();
    void Close();
    void Update(const GameInput& gameInput, float deltaTimeSeconds);
    void Draw(Renderer &renderer);
};

#endif
