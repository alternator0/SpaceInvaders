#pragma once
#include <vector>
#include "raylib.h"
#include "Laser.h"

class Spaceship{
    Texture2D m_image{};
    Vector2 m_position{100,100};
    int m_speed{7};
    float m_lastFireTime{0.0};
    std::vector<Laser> m_lasers{};
    

    public:
    Spaceship();
    Spaceship(float x, float y);
    std::vector<Laser>& lasers(){return m_lasers;}
    float getLastFireTime() const {return m_lastFireTime;}
    void setLastFireTime(float x) {m_lastFireTime = x;}
    void getHit(std::vector<Laser>& lasers, int& health);
    void moveLeft();
    void moveRight();
    void shoot();
    void draw()const ;
    void update();
    ~Spaceship();
};