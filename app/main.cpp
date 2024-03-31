#include <iostream>
#include "raylib.h"
#include "Game.h"
#include "Invader.h"

int main() {
    const int screenWidth{800};
    const int screenHeight{450};
    InitWindow(screenWidth, screenHeight, "Space Invaders");
    SetTargetFPS(60);

    Game game{};
    game.createInvaders();

    while (!WindowShouldClose()) {

        game.update();
        BeginDrawing();
        game.draw();
        ClearBackground({29,29,27,255});
        EndDrawing();


    }
    return 0;
}