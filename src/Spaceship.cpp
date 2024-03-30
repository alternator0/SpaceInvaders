#include "Spaceship.h"
#include <vector>
#include "Laser.h"
#include "raylib.h"

Spaceship::Spaceship() {
    m_image      = LoadTexture("../assets/spaceship.png");
    m_position.x = ((GetScreenWidth() - m_image.width) / 2);
    m_position.y = (GetScreenHeight() - m_image.height);
}

Spaceship::Spaceship(float x, float y) : m_position{x, y} {
    m_image = LoadTexture("../assets/spaceship.png");
}

Spaceship::~Spaceship() {
    UnloadTexture(m_image);
}

void Spaceship::moveLeft() {
    if (m_position.x != 0)
        m_position.x -= m_speed;
}

void Spaceship::moveRight() {
    if (m_position.x + m_image.width != GetScreenWidth())
        m_position.x += m_speed;
}

void Spaceship::shoot() {
    if (GetTime() - getLastFireTime() >= 0.40) {
        m_lasers.push_back(
            Laser{{m_position.x + (m_image.width / 2), m_position.y}, -6});
        setLastFireTime(GetTime());
    }
}

void Spaceship::update() {
    if (IsKeyDown(KEY_D)) {
        moveRight();
    }
    if (IsKeyDown(KEY_A)) {
        moveLeft();
    }
    if (IsKeyDown(KEY_SPACE)) {
        shoot();
    }
}

void Spaceship::draw() const {
    DrawTextureV(m_image, m_position, WHITE);
}
