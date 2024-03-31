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
    }

    updateLasers();
    deleteInactiveLasers();
    deleteInactiveInvaders();

    m_cover.update(m_player.lasers(), m_invaders);
}

void Game::draw() {
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
}

void Game::createInvaders() {
    float spaceBetweenY{static_cast<float>(GetScreenHeight()) / 10};
    m_row = 11;
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
    static Invader rightMostInvader{m_invaders.at(21)};
    static float positionRight{rightMostInvader.getPosition().x + rightMostInvader.getImages()[rightMostInvader.getType()].width};
    static float positionLeft{m_invaders.at(0).getPosition().x};
    if (positionRight > GetScreenWidth()|| positionLeft < 0){
        speed = -speed;
        y = 2;
    }
    positionRight +=speed;
    positionLeft += speed;

    for (Invader& invader: m_invaders){
        invader.move(speed,y);
    }
}
//