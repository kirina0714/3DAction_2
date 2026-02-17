#pragma once
#include "DxLib.h"
#include <cmath>

enum class TileType 
{
    Floor, // 通常床 
    Hole,  // 穴 
    Wall // 壁（侵入不可） 
};

struct FloorTile
{
    int grid_x;   // 升目座標
    int grid_z;   // 升目座標
    VECTOR pos;
    VECTOR size;
    TileType type; // ステージ構造体 
    bool stepped; // Floor のみ有効
};

class Stage
{
public:
    Stage();
    void Update(const VECTOR& playerPos);
    void Draw();
    bool CanEnter(const VECTOR& nextPos) const; 
    VECTOR GetTileCenter(int gx, int gz) const;

private:
    int test;
    static const int GRID_W = 11;
    static const int GRID_H = 11;
    FloorTile tiles[GRID_W * GRID_H];
};

