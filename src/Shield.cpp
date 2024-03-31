#include "Shield.h"
#include <array>
#include "Block.h"
#include "raylib.h"
#include "Laser.h"

Shield::Shield(float a, float b, float width)
    : m_position{a, b}, m_width{width} {
    for (int y{0}; y < m_grid.size(); ++y) {
        for (int x{0}; x < m_grid.at(y).size(); ++x) {
            if (m_grid[y][x]) {
                m_blocks.push_back(Block{x * m_width + m_position.x,
                                         y * m_width + m_position.y, m_width,
                                         true});
            }
        }
    }
}



void Shield::draw() {
    for (const auto& x : m_blocks) {
        x.draw();
    }
}



void Shield::update(Laser& laser) {
    for (auto it{m_blocks.begin()}; it < m_blocks.end();) {
        it->update(laser);
        !it->isActive() ? m_blocks.erase(it) : ++it;
        
    }
}