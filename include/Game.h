#pragma once
#include <array>
#include "Laser.h"
#include "Shield.h"
#include "Spaceship.h"
#include "raylib.h"
#include "Cover.h"
#include "Fleet.h"

class Game {
    Spaceship m_player{};
    //Invader m_invader{100,100,LoadTexture("../assets/alien_1.png")};
    Fleet<5> m_fleet{100, LoadImage("../assets/alien_1.png")};
    Cover<4,3.0f> m_cover{};

public:
    Game() = default;
    void updateLasers();
    void deleteInactiveLasers();
    void deleteInactiveInvaders();
    void update();
    void draw();
};