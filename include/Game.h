#pragma once
#include <array>
#include "Laser.h"
#include "Shield.h"
#include "Spaceship.h"
#include "raylib.h"
#include "Cover.h"
#include "Invader.h"

class Game {
    Spaceship m_player{};
    std::vector<Invader> m_invaders{};
    //Invader m_invader{100,100,Invader::alien3};
    Rectangle m_legion{};
    Cover<4,3.0f> m_cover{};
    int m_column{};
    int m_row{};

public:
    Game() = default;
    ~Game();
    void updateLasers();
    void deleteInactiveLasers();
    void deleteInactiveInvaders();
    void moveInvaders();
    void update();
    void draw();
    void createInvaders();
};