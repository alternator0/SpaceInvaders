#pragma once
#include "raylib.h"
#include <iostream>
#include "Laser.h"

class Block {
    Rectangle m_block{};
    bool m_isActive{false};
    Color m_color{243,216,63,255};

public:
    Block() = default;
    Block(float x, float y, float width, bool a);
    bool isActive() const{ return m_isActive;};
    void turnOff();
    void update(Laser& laser);
    void draw() const ;
};