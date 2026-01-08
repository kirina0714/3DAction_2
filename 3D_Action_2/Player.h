#pragma once
#include "DxLib.h"
#include <cmath>

class Player
{
public:
    Player();
    void Update();
    void Draw();
    void Move();
    void ChangeAnimation(int anim_id);

    VECTOR pos;              // キャラクター位置取得

    float angleY = 0;        // ラジアン(方向角度)

private:
    int model;               // キャラクターハンドル取得
    float moveSpeed = 1.0f;  // 歩行速度
    float dashSpeed = 0.1f;  // ダッシュ速度
    
    float anim_time = 0.0f;  // アニメ全体の長さ
    float anim_timer = 0.0f; // 再生中の時間

    bool isGround = true;    // 接地しているか

    VECTOR GetHitPos() const { return pos; }
    float  GetHitRadius() const { return 15.0f; } // 仮半径

};


