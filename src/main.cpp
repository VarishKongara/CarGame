#include <raylib.h>

int main() {
  // Window setup
  const int screenWidth = 1920;
  const int screenHeight = 1080;
  InitWindow(screenWidth, screenHeight, "CarGame");

  // Camera setup
  Camera3D camera{};
  camera.position = {4.0f, 4.0f, 4.0f};
  camera.target = {0.0f, 1.0f, 0.0f};
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 60.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  SetTargetFPS(60);

  // Main loop
  while (!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_ORBITAL); // Orbit around target with mouse

    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);
    DrawCube({0.0f, 0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, RED);
    DrawCubeWires({0.0f, 0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, MAROON);
    DrawGrid(10, 1.0f); // XZ grid
    EndMode3D();

    DrawText("CarGame", 10, 40, 20, DARKGRAY);
    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
