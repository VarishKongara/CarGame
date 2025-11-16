#include "Game.h"

#include <raylib.h>

#include "Renderer.h"
Game::Game(Renderer& rendererRef) : renderer(rendererRef)
{
}

void Game::Start()
{
}

void Game::Update()
{
    UpdateCamera();
}

void Game::UpdateCamera()
{
    ::UpdateCamera(&this->renderer.GetCamera(), CAMERA_ORBITAL);
}

void Game::Render3D()
{
    this->renderer.Begin3D();
    this->renderer.DrawCube({0.0f, 0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, RED);
    this->renderer.DrawCubeWires({0.0f, 0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, MAROON);
    this->renderer.DrawGrid(10, 1.0f);
    this->renderer.End3D();
    this->renderer.DrawText("CarGame", 10, 40, 20, DARKGRAY);
    this->renderer.DrawFPS(10, 10);
}
