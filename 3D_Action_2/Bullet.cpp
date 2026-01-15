#include "Bullet.h"

Bullet::Bullet(VECTOR startPos)
{
    pos = startPos;
    size = VGet(20.0f, 20.0f, 20.0f);   // “–‚½‚è”»’èBOX
    vel = VGet(0.0f, 0.0f, -5.0f); // -Z•ûŒü‚É”ò‚Î‚·
}

void Bullet::Update()
{
    pos = VAdd(pos, vel);
}

void Bullet::Draw()
{
    VECTOR minPos = VSub(pos, size);
    VECTOR maxPos = VAdd(pos, size);

    DrawCube3D(
        minPos,
        maxPos,
        GetColor(255, 0, 0),
        GetColor(255, 255, 255),
        FALSE
    );
}