#include "Laser.h"
#include "raylib.h"

Laser::Laser(Vector2 position, int speed)
    : m_laser{position.x, position.y, 4, 15}, m_speed{speed} {}

void Laser::update() {
    if (m_isActive)
        m_laser.y += m_speed;
    if (m_laser.y < (GetScreenHeight() / 50) ||
        (m_laser.y + m_laser.height >
         (GetScreenHeight() - (GetScreenHeight() / 50)))) {
        m_isActive = false;
    }
}

void Laser::draw() const {
    DrawRectangleRec(m_laser, {243, 216, 63, 255});
}
