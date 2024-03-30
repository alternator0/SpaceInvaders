#include "Invader.h"
#include <string_view>
#include <vector>
#include "Random.h"
#include "iostream"
#include "raylib.h"

Invader::Invader(float x, float y) : m_position{x, y} {
    m_image = LoadTexture("../assets/titles.png");
}

void Invader::shoot() {
    if (Random::get(0, 60) == 1) {
        m_lasers.push_back(Laser{
            {m_position.x + (m_image.width / 2), m_position.y + m_image.height},
            6});
    }
}

void Invader::getHit(Laser& laser) {
    if (CheckCollisionRecs(
            {m_position.x, m_position.y, static_cast<float>(m_image.width),
             static_cast<float>(m_image.height)},
            laser.m_laser)){
        m_isActive = false;
        laser.turnOff();
        }
}

void Invader::draw() {
    DrawTextureV(m_image, m_position, {255, 255, 255, 255});
}

void Invader::update(Laser& laser) {
    //shoot();
    //getHit(laser);
}

Invader::~Invader() {
    //UnloadTexture(m_image);
}

void Invader::setImage(Texture2D&& x) {
    m_image = x;
}

void Invader::setImage(std::string_view x) {
    m_image = LoadTexture("../assets/alien_1.png");
}