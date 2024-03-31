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
    Vector2 m_position{};

public:

    Invader(float x, float y, AlienType type);
    ~Invader();
    void shoot(std::size_t size);
    Vector2 getPosition()const {return m_position;};
    void getHit(std::vector<Laser>& lasers);
    bool isActive() const { return m_isActive; }
    std::vector<Laser>& lasers() { return m_lasers; }
    AlienType getType(){return m_type;}
    void move(float x, float y);
    void draw();
    void update(std::vector<Laser>& lasers, std::size_t size);
    static void unloadImages();
    Texture2D* getImages(){return m_images;}
};
