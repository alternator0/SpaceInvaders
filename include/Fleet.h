#pragma once
#include <string_view>
#include <utility>
#include <vector>
#include "Invader.h"
#include "Laser.h"
#include "raylib.h"
template <int size>
class Fleet {
    std::vector<Invader> m_invaders{};
    Vector2 m_position{};
    Image m_texture{};

public:
    Fleet(float y, Image&& texture);
    std::vector<Invader>& invaders() { return m_invaders; }
    Vector2 getPosition() const { return m_position; }
    void update(std::vector<Laser>& lasers);
    void draw();
};

template <int size>
Fleet<size>::Fleet(float y, Image&& texture) : m_texture{texture} {
    for (int i{0}; i < size; ++i) {
        m_invaders.push_back(Invader{
            static_cast<float>(((GetScreenWidth() / (size + 1) * (i + 1) -
                                 (m_texture.width / 2)))),
            y});
        // m_invaders.at(i).setImage("../assets/alien_1.png");
        m_invaders.at(i).setImage(std::move(LoadTextureFromImage(texture)));
    }
}

template <int size>
inline void Fleet<size>::update(std::vector<Laser>& lasers) {
    for (Invader& x : m_invaders) {
        x.shoot();
        for (Laser& laser: lasers)
        x.getHit(laser);
    }
}

template <int size>
void Fleet<size>::draw() {
    for (Invader& x : m_invaders) {
        x.draw();
    }
}
