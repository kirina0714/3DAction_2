#pragma once
#include "DxLib.h"

class Bullet
{
public:
    Bullet(VECTOR startPos);

    void Update();
    void Draw();

    VECTOR pos;   // 位置
    VECTOR size;  // 箱サイズ
    VECTOR vel;   // 移動量
};

