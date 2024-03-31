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
    int m_health{3};
    bool m_run{true};

public:
    Game() = default;
    ~Game();
    void turnOn();
    void updateLasers();
    void deleteInactiveLasers();
    void deleteInactiveInvaders();
    void moveInvaders();
    void drawHealth();
    void update();
    void gameOver();
    bool isRunning(){return m_run;};
    void draw();
    void createInvaders();
};