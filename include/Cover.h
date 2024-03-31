#pragma once
#include <vector>
#include "Shield.h"
#include "Invader.h"
template <int size, float width>
class Cover {
    std::vector<Shield> m_cover{};

public:

    Cover();
    void update(std::vector<Laser>& playerLasers,std::vector<Invader>& invaders);
    void draw();
};
#include "Cover.inl"