#include <raylib.h>

#include "Game.h"
#include "Renderer.h"

int main()
{
    // Window setup
    int screenWidth = 1920;
    int screenHeight = 1080;
    int targetFPS = 60;

    Renderer renderer(screenWidth, screenHeight, "CarGame", targetFPS);

    Game game(renderer);

    game.Start();
    // Main loop
    while (!WindowShouldClose())
    {
        game.Update();
        renderer.BeginFrame();
        game.Render3D();
        renderer.EndFrame();
    }

    CloseWindow();
    return 0;
}
