#include "Stage.h"

Stage::Stage()
{
    test = MV1LoadModel("Res/Stage/Island/Island.mv1");
    MV1SetScale(test, VGet(10.0f, 10.0f, 10.0f));
    MV1SetPosition(test, VGet(0, 0, 0));
    MV1SetUseZBuffer(test, true);
    MV1SetWriteZBuffer(test, true);

    int index = 0; // 配列番号
    for (int z = 0; z < GRID_H; z++)
    {
        for (int x = 0; x < GRID_W; x++)
        {
            tiles[index].grid_x = x;
            tiles[index].grid_z = z;
            tiles[index].pos = VGet(x * 16.0f, 0.0f, z * 16.0f);
            tiles[index].size = VGet(8.0f, 2.0f, 8.0f);
            tiles[index].stepped = false;

            tiles[index].exists = true;  // 基本は床あり

            // 中央を穴にする
            if (x == 1 && z == 1)
            {
                tiles[index].exists = false;
            }

            index++;
        }
    }
}

void Stage::Update(const VECTOR& playerPos)
{
    const float TILE_SIZE = 16.0f;

    int gx = (int)std::floor(playerPos.x / TILE_SIZE);
    int gz = (int)std::floor(playerPos.z / TILE_SIZE);

    // 範囲外チェック
    if (gx < 0 || gx >= GRID_W || gz < 0 || gz >= GRID_H)
    {
        return;
    }
        
    int index = gz * GRID_W + gx;

    FloorTile& tile = tiles[index];

    if (!tiles[index].stepped)
    {
        tiles[index].stepped = true;
    }
}




void Stage::Draw()
{
#if 0
    MV1DrawModel(test);
#else
    for (int i = 0; i < GRID_W * GRID_H; i++)
    {
        int color = tiles[i].stepped
            ? GetColor(0, 200, 255)   // 踏んだ後
            : GetColor(200, 200, 200); // 未踏

        VECTOR minPos = tiles[i].pos;
        VECTOR maxPos = VAdd(tiles[i].pos, VGet(16.0f, 4.0f, 16.0f));

        // 底面
        DrawCube3D(
            minPos,
            maxPos,
            color,
            color,
            TRUE
        );

        // 枠線（黒）
        DrawCube3D(
            minPos,
            maxPos,
            GetColor(0, 0, 0),
            GetColor(0, 0, 0),
            FALSE
        );
    }
#endif
}
