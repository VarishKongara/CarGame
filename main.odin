package main

import "core:fmt"
import rl "vendor:raylib"

main :: proc() {
	fmt.println("Hello Word")

	rl.InitWindow(1920, 1080, "CarGame")

	for !rl.WindowShouldClose() {
		rl.BeginDrawing()
		rl.ClearBackground({120, 255, 255, 255})
		rl.EndDrawing()
	}

	rl.CloseWindow()
}
