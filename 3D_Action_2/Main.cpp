#include "DxLib.h"
#include "Player.h"
#include "Stage.h"
#include "Bullet.h"

bool CheckSphereHit(VECTOR aPos, float aR, VECTOR bPos, float bR)
{
    float dx = aPos.x - bPos.x;
    float dy = aPos.y - bPos.y;
    float dz = aPos.z - bPos.z;

    float distSq = dx * dx + dy * dy + dz * dz;
    float hitDist = aR + bR;

    return distSq <= hitDist * hitDist;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);                 // ウィンドウモード

    SetGraphMode(1280, 720, 32);            // 画面サイズ

    if (DxLib_Init() < 0)                   // DXライブラリ初期化
    {
        return -1;
    }

    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);
        
    //SetBackgroundColor(150, 255, 255); // 背景色（空色）
    SetDrawScreen(DX_SCREEN_BACK);          // 裏画面

    Player player;                          // プレイヤー生成
    Stage stage;                         // ステージ生成
    
    SetCameraNearFar(1.0f, 1000.0f);

    while (ProcessMessage() == 0)
    {

        // カメラ追従（TPS）
        float camDis = 80.0f;   // プレイヤーとの距離
        float camHeight = 30.0f; // カメラの高さ

        VECTOR camPos = VGet(
            player.pos.x,
            player.pos.y + camHeight,
            player.pos.z + camDis
        );

        VECTOR camTag = VGet(
            player.pos.x,
            player.pos.y + camHeight,
            player.pos.z
        );

        SetCameraPositionAndTarget_UpVecY(camPos, camTag);

        ClearDrawScreen();

        // 描画
        stage.Update();  // ステージ更新
        player.Update();  // プレイヤー更新
        
        // 更新
        stage.Draw();    // ステージ描画
        player.Draw();    // プレイヤー描画

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}

