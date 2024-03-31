#include "Game.h"
#include "Cover.h"
// #include "Fleet.h"
//  #include "Invader.h"
#include <cassert>
#include <iostream>
#include "Invader.h"
#include "Laser.h"

Game::~Game() {
    Invader::unloadImages();
}

void Game::turnOn() {
    m_run = true;
    createInvaders();
    m_cover    = Cover<4, 3.0f>();
    m_health   = 3;
    m_wasReset = true;
    moveInvaders();
}

void Game::updateLasers() {
    for (Laser& laser : m_player.lasers()) {
        laser.update();
    }
    for (Invader& invader : m_invaders) {
        for (Laser& laser : invader.lasers()) {
            laser.update();
        }
    }
}

void Game::deleteInactiveLasers() {
    for (auto it{m_player.lasers().begin()}; it < m_player.lasers().end();) {
        !it->isActive() ? m_player.lasers().erase(it) : ++it;
    }

    for (Invader& invader : m_invaders)
        for (auto it{invader.lasers().begin()}; it < invader.lasers().end();) {
            !it->isActive() ? invader.lasers().erase(it) : ++it;
        }
}

void Game::deleteInactiveInvaders() {
    for (auto it{m_invaders.begin()}; it < m_invaders.end();) {
        !it->isActive() ? m_invaders.erase(it) : ++it;
    }
}

void Game::update() {
    m_player.update();
    // m_invader.shoot();
    // m_invader.getHit(m_player.lasers());

    moveInvaders();
    //// m_invader.update();
    for (Invader& invader : m_invaders) {
        invader.update(m_player.lasers(), m_invaders.size());
        m_player.getHit(invader.lasers(), m_health);
    }

    updateLasers();
    deleteInactiveLasers();
    deleteInactiveInvaders();

    m_cover.update(m_player.lasers(), m_invaders);
    if (m_health == 0) {
        m_run = false;
        for (Invader& invader : m_invaders)
            invader.turnOff();
    }
}

void Game::gameOver() {
    DrawText("GAME OVER", 100, 100, 40, RED);
    DrawText("Do you want to continue?", 170, 300, 30, ORANGE);
    DrawText("For yes press ENTER", 170, 350, 20, GRAY);
}

void Game::draw() {
    DrawRectangleRoundedLines(
        Rectangle{
            static_cast<float>(GetScreenWidth() / 50),
            static_cast<float>(GetScreenHeight() / 50),
            static_cast<float>(GetScreenWidth() - (GetScreenWidth() / 50 * 2)),
            static_cast<float>(GetScreenHeight() -
                               (GetScreenHeight() / 50 * 2))},
        0.15f, 0, 3, {243, 216, 63, 255});
    m_player.draw();
    for (const Laser& laser : m_player.lasers()) {
        laser.draw();
    }

    m_cover.draw();

    // m_invader.draw();
    for (Invader& invader : m_invaders) {
        invader.draw();
        for (Laser& laser : invader.lasers())
            laser.draw();
    }
    drawHealth();
}

void Game::createInvaders() {
    float spaceBetweenY{static_cast<float>(GetScreenHeight()) / 10};
    m_row    = 11;
    m_column = 5;
    Invader::AlienType type{};
    for (int y{0}; y < m_column; ++y) {
        for (int x{0}; x < m_row; ++x) {
            if (y == 0) {
                type = Invader::alien3;
            } else if (y == 1 || y == 2) {
                type = Invader::alien2;
            } else {
                type = Invader::alien1;
            }
            float positionX{static_cast<float>(GetScreenWidth()) / (m_row + 1) *
                            (x + 1)};
            float positionY{spaceBetweenY * y + 50};
            m_invaders.push_back({positionX, positionY, type});
        }
    }
}

void Game::moveInvaders() {
    static float speed{1};
    float y{0};
    static Invader rightMostInvader{m_invaders.back()};
    static float positionRight{
        rightMostInvader.getPosition().x +
        rightMostInvader.getImages()[rightMostInvader.getType()].width};
    static float positionLeft{m_invaders.at(0).getPosition().x};
    const static int rightWall{GetScreenWidth() - (GetScreenWidth() / 50)};
    const static int leftWall{GetScreenWidth() / 50};
    // Rectangle{GetScreenWidth() / 50, GetScreenHeight() / 50,
    //       GetScreenWidth() - (GetScreenWidth() / 50 *2),
    //       GetScreenHeight() - (GetScreenHeight() / 50*2)};
    //
    if (m_wasReset) {
        rightMostInvader = m_invaders.back();
        positionRight =
            rightMostInvader.getPosition().x +
            rightMostInvader.getImages()[rightMostInvader.getType()].width;
        positionLeft = m_invaders.at(0).getPosition().x;
        m_wasReset   = false;
    }
    if (positionRight > static_cast<float>(rightWall) ||
        positionLeft < static_cast<float>(leftWall)) {
        speed = -speed;
        y     = 2;
    }
    positionRight += speed;
    positionLeft += speed;

    for (Invader& invader : m_invaders) {
        invader.move(speed, y);
    }
}
void Game::drawHealth() {
    // const static Texture2D healthTx{LoadTexture("../assets/heart.png")};
    Vector2 size{GetScreenWidth() / 32, GetScreenHeight() / 60};
    for (int i{0}; i < m_health; ++i) {
        DrawRectangleV(
            Vector2{(i * ((size.x) + (0.4f * size.x)) + GetScreenWidth() / 16),
                    (GetScreenHeight() - GetScreenHeight() / 50 - 5) - size.y},
            size, RED);
    }
    // DrawTextureV(
    //     healthTx,
    //     Vector2{static_cast<float>(i) *
    //                 (healthTx.width + (0.4f * healthTx.width)),
    //             static_cast<float>(GetScreenHeight()) - healthTx.height},
    //     WHITE);
}

//