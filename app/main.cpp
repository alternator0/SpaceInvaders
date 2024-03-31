#include <iostream>
#include "Game.h"
#include "Invader.h"
#include "raylib.h"

int main() {
    const int screenWidth{800};
    const int screenHeight{600};
    InitWindow(screenWidth, screenHeight, "Space Invaders");
    SetTargetFPS(60);

    Game game{};
    game.createInvaders();

    while (!WindowShouldClose()) {
        if (game.isRunning()) {
            game.update();
        } else if (IsKeyPressed(KEY_ENTER)) {
            game.turnOn();
        }

        BeginDrawing();
        if (game.isRunning()) {
            game.draw();
            if (game.getInvaders().empty()) {
                DrawText("Well Played", 200, 200, 70, {117, 122, 176, 255});
            }
        } else {
            game.gameOver();
        }
        ClearBackground({29, 29, 27, 255});
        EndDrawing();
    }
    return 0;
}
