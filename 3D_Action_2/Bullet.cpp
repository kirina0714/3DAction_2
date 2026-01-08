#include "Bullet.h"

Bullet::Bullet(VECTOR startPos)
{
    pos = startPos;
    vel = VGet(0.0f, 0.0f, -5.0f); // Zマイナス方向に飛ばす
}

void Bullet::Update()
{
    pos = VAdd(pos, vel);

    // 遠く行ったら消す
    if (pos.z < -1000.0f)
    {
        isAlive = false;
    }
}

void Bullet::Draw()
{
    DrawSphere3D(
        pos,
        GetRadius(),
        8,
        GetColor(255, 0, 0),
        GetColor(255, 0, 0),
        TRUE
    );
}