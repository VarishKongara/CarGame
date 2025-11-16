#pragma once
#include <raylib.h>

#include <string>

class Renderer
{
private:
    Camera3D camera;
    int screenWidth;
    int screenHeight;
    int targetFPS;

public:
    Renderer(int screenWidth, int screenHeight, std::string title, int targetFPS);

    Camera3D& GetCamera() { return camera; }

    void BeginFrame();
    void Begin3D();
    void End3D();
    void EndFrame();

    void DrawCube(Vector3 pos, float width, float height, float length, Color color);
    void DrawCubeWires(Vector3 pos, float width, float height, float length, Color color);
    void DrawGrid(int slices, float spacing);
    void DrawText(const char* text, int posX, int posY, int fontSize, Color color);
    void DrawFPS(int posX, int posY);
};
