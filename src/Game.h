#pragma once

#include <raylib.h>

#include "Renderer.h"

class Game
{
private:
    Renderer& renderer;

public:
    Game(Renderer& renderer);

    void Start();
    void Update();
    void Render3D();
    void UpdateCamera();
};
