#pragma once
#include <string>
#include <vector>
#include "Laser.h"
#include "raylib.h"
#include <string_view>
class Invader {
    Texture2D m_image{LoadTexture("../assets/titles.png")};
    Vector2 m_position{};
    std::vector<Laser> m_lasers{};
    bool m_isActive{true};

public:
    Invader(float x, float y);
    ~Invader();
    void setImage(Texture2D&& x);
    void setImage(std::string_view x);
    Texture2D getImage()const {return m_image;}
    void shoot();
    void getHit(Laser& laser);
    bool isActive() const { return m_isActive; }
    std::vector<Laser>& lasers() { return m_lasers; }
    void draw();
    void update(Laser& laser);
};