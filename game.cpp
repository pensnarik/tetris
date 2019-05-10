#include "game.h"
#include "renderer.h"

Game::Game()
{

}

Game::~Game()
{

}

bool Game::Init()
{
    return true;
}

void Game::Close()
{

}

void Game::Update(const GameInput& gameInput, float deltaTimeSeconds)
{

}

void Game::Draw(Renderer &renderer)
{
    renderer.DrawSolidRect(100, 100, 32, 32, 0x00ff00);
}
