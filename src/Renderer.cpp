#include "Renderer.h"

#include <raylib.h>

Renderer::Renderer(int width, int height, std::string title, int fps)
    : screenWidth(width), screenHeight(height), targetFPS(fps)
{
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(this->targetFPS);

    this->camera.position = {4.0f, 4.0f, 4.0f};
    this->camera.target = {0.0f, 1.0f, 0.0f};
    this->camera.up = {0.0f, 1.0f, 0.0f};
    this->camera.fovy = 60.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
}

void Renderer::BeginFrame()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Renderer::Begin3D()
{
    BeginMode3D(this->camera);
}

void Renderer::End3D()
{
    EndMode3D();
}

void Renderer::EndFrame()
{
    EndDrawing();
}

void Renderer::DrawCube(Vector3 pos, float width, float height, float length, Color color)
{
    ::DrawCube(pos, width, height, length, color);
}

void Renderer::DrawCubeWires(Vector3 pos, float width, float height, float length, Color color)
{
    ::DrawCubeWires(pos, width, height, length, color);
}

void Renderer::DrawGrid(int slices, float spacing)
{
    ::DrawGrid(slices, spacing);
}

void Renderer::DrawText(const char* text, int posX, int posY, int fontSize, Color color)
{
    ::DrawText(text, posX, posY, fontSize, color);
}

void Renderer::DrawFPS(int posX, int posY)
{
    ::DrawFPS(posX, posY);
}
