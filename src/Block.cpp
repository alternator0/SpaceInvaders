#include "Block.h"
#include "raylib.h"
#include "Laser.h"

Block::Block(float x, float y, float width, bool a):m_block{x, y, width, width}, m_isActive{a} {
}

void Block::turnOff() {
    m_isActive = false;
}

void Block::update(Laser& laser) {
    if (CheckCollisionRecs(m_block, laser.m_laser)){
        turnOff();
        laser.turnOff();
    }
}
void Block::draw() const {
    if (isActive())
    DrawRectangleRec(m_block, m_color);
}
