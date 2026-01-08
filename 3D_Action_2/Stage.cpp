#include "Stage.h"

Stage::Stage()
{
    test = MV1LoadModel("Res/Stage/Island/Island.mv1");
    MV1SetScale(test, VGet(10.0f, 10.0f, 10.0f));
    MV1SetPosition(test, VGet(0, 0, 0));
    MV1SetUseZBuffer(test, true);
    MV1SetWriteZBuffer(test, true);

    //pos = VGet(0.0f, 0.0f, 0.0f);      // 中心
    //size = VGet(1000.0f, 20.0f, 1000.0f); // 横・高さ・奥行
}

void Stage::Update()
{
    
}

void Stage::Draw()
{
    MV1DrawModel(test);
    /*DrawBox3D(
        VSub(pos, VScale(size, 0.5f)),
        VAdd(pos, VScale(size, 0.5f)),
        GetColor(100, 200, 100),
        TRUE
    );*/
}
