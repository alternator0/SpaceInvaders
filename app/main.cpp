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
            game.deleteInactiveInvaders();
            game.turnOn();
        }

        BeginDrawing();
        if (game.isRunning()) {
            game.draw();
        } else {
            game.gameOver();
        }
        ClearBackground({29, 29, 27, 255});
        EndDrawing();
    }
    return 0;
}
