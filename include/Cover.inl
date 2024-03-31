#include "Laser.h"
#include "Shield.h"
#include "Invader.h"

template <int size, float width>
Cover<size, width>::Cover() {
    for (int i{0}; i < size; ++i) {
        m_cover.push_back(Shield{
            static_cast<float>(((GetScreenWidth() / (size + 1)) * (i + 1)) -
                               (width * 23.0f / 2)),
            static_cast<float>(GetScreenHeight() * 7 / 9), width});
    }
}

template <int size, float width>
void Cover<size, width>::update(std::vector<Laser>& playerLasers,
                                std::vector<Invader>& invaders) {
    for (Laser& laser : playerLasers) {
        for (Shield& shield : m_cover) {
            shield.update(laser);
        }
    }
    for (Invader& invader : invaders) {
        for (Laser& invLaser : invader.lasers()) {
            for (Shield& shield : m_cover) {
                shield.update(invLaser);
            }
        }
    }
}

template <int size, float width>
void Cover<size, width>::draw() {
    for (Shield& shield : m_cover) {
        shield.draw();
    }
}