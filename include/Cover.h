#pragma once
#include <vector>
#include "Shield.h"
template <int size, float width>
class Cover {
    std::vector<Shield> m_cover{};

public:

    Cover();
    void update(std::vector<Laser>& lasers);
    void draw();
};
#include "Cover.inl"