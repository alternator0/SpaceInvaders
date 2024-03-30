#pragma once
#include "raylib.h"

class Laser {
    private:
    int m_speed{6};
    bool m_isActive{true};

    public:
    explicit Laser() = default;
    Rectangle m_laser{};
    Laser(Vector2 position, int speed);
    bool isActive() const {return m_isActive;}
    void turnOff() {m_isActive = false;}
    void update();
    void draw()const;
};