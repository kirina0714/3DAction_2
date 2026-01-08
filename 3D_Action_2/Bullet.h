#pragma once
#include "DxLib.h"

class Bullet
{
public:
    Bullet(VECTOR startPos);
    void Update();
    void Draw();

    bool IsAlive() const { return isAlive; }
    VECTOR GetPos() const { return pos; }
    float GetRadius() const { return 5.0f; }

private:
    VECTOR pos;
    VECTOR vel;
    bool isAlive = true;
};

