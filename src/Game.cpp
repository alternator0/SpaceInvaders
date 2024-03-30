#include "Game.h"
#include "Cover.h"
#include "Fleet.h"
//#include "Invader.h"
#include "Laser.h"

void Game::updateLasers() {
    for (Laser& laser : m_player.lasers()) {
        laser.update();
    }

    for (Invader& invader : m_fleet.invaders()) {
        for (Laser& laser : invader.lasers())
            laser.update();
    }
}

void Game::deleteInactiveLasers() {
    for (auto it{m_player.lasers().begin()}; it < m_player.lasers().end();) {
        !it->isActive() ? m_player.lasers().erase(it) : ++it;
    }
    for (Invader& invader : m_fleet.invaders()) {
        for (auto it{invader.lasers().begin()}; it < invader.lasers().end();) {
            !it->isActive() ? invader.lasers().erase(it) : ++it;
        }
    }
}
void Game::deleteInactiveInvaders() {
        for (auto it{m_fleet.invaders().begin()}; it < m_fleet.invaders().end();) {
        !it->isActive() ? m_fleet.invaders().erase(it) : ++it;
    }
}
void Game::update() {
    m_player.update();
    //m_invader.update();
    
    updateLasers();
    deleteInactiveLasers();
    deleteInactiveInvaders();
    m_fleet.update(m_player.lasers());
    m_cover.update(m_player.lasers());
    for (auto& x: m_fleet.invaders())
    m_cover.update(x.lasers());
}

void Game::draw() {
    m_player.draw();
    for (const Laser& laser : m_player.lasers()) {
        laser.draw();
    }
    for (Invader& invader : m_fleet.invaders())
        for (const Laser& laser : invader.lasers()) {
            laser.draw();
        }
    m_cover.draw();
    //m_invader.draw();
    m_fleet.draw();
}
