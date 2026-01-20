#pragma once
#include "DxLib.h"
#include <cmath>

struct FloorTile
{
    int grid_x;   // è°ñ⁄ç¿ïW
    int grid_z;   // è°ñ⁄ç¿ïW
    VECTOR pos;
    VECTOR size;
    bool stepped;         // ì•Ç‹ÇÍÇΩÇ©
    bool exists;          // è∞Ç™Ç†ÇÈÇ©
};

class Stage
{
public:
    Stage();
    void Update(const VECTOR& playerPos);
    void Draw();

private:
    int test;
    static const int GRID_W = 3;
    static const int GRID_H = 3;
    FloorTile tiles[GRID_W * GRID_H];
};

