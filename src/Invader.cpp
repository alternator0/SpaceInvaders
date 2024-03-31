#include "Invader.h"
#include <string_view>
#include <vector>
#include "Random.h"
#include "iostream"
#include "raylib.h"
#include <iostream>

Texture2D Invader::m_images[3]{};

Invader::Invader(float x, float y, AlienType type): m_position{x, y}, m_type{type} {
    if (m_images[type - 1].id == 0) {
        switch (type) {
            case alien1:
                m_images[0] = LoadTexture("../assets/alien_1.png");
                break;
            case alien2:
                m_images[1] = LoadTexture("../assets/alien_2.png");
                break;
            case alien3:
                m_images[2] = LoadTexture("../assets/alien_3.png");
                break;
        }
    }
}

void Invader::shoot(std::size_t size) {
    if (Random::get(0, 20 * (static_cast<int>(size)/2)) == 1) {
        m_lasers.push_back(Laser{
            {m_position.x + (m_images[m_type].width / 2), m_position.y + m_images[m_type].height},
            6});
    }
}

void Invader::getHit(std::vector<Laser>& lasers) {
    for (Laser& laser : lasers) {
        if (CheckCollisionRecs(
                {m_position.x, m_position.y, static_cast<float>(m_images[m_type].width),
                 static_cast<float>(m_images[m_type].height)},
                laser.m_laser)) {
            m_isActive = false;
            laser.turnOff();
        }
    }
}

void Invader::move(float x, float y) {
    m_position.x +=x;
    m_position.y +=y;
}

void Invader::draw() {
    DrawTextureV(m_images[m_type], m_position, {WHITE});
}

void Invader::update(std::vector<Laser>& lasers,std::size_t size) {
    shoot(size);
    getHit(lasers);
}

Invader::~Invader() {
    // UnloadTexture(m_image);
}

//void Invader::setImage(Texture2D&& x) {
//    m_image = x;
//}

//void Invader::setImage(std::string_view x) {
//    m_image = LoadTexture("../assets/alien_1.png");
//}

 void Invader::unloadImages(){
    for (int i{0}; i < 3; ++i)
    UnloadTexture(m_images[i]);
 }