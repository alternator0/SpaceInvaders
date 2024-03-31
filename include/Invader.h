#pragma once
#include <string>
#include <string_view>
#include <vector>
#include "Laser.h"
#include "raylib.h"
class Invader {
public:
    enum AlienType { alien1, alien2, alien3, max_alien_types };

private:
    static Texture2D m_images[3];
    
    std::vector<Laser> m_lasers{};
    bool m_isActive{true};
    AlienType m_type{};

public:
Vector2 m_position{};
    Invader(float x, float y, AlienType type);
    ~Invader();
    //void shoot();
    //void getHit(std::vector<Laser>& lasers);
    bool isActive() const { return m_isActive; }
    std::vector<Laser>& lasers() { return m_lasers; }
    void draw();
    void update(std::vector<Laser>& lasers);
    static void unloadImages();
};
