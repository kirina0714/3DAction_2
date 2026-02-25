#include "Player.h"

Player::Player()
{
    model = MV1LoadModel("Res/Miku/Miku.mv1");
    pos = VGet(0.0f, 0.0f, 0.0f);
    size = VGet(5.0f, 20.0f, 10.0f); // 幅・高さ・奥行
    
    MV1SetScale(model, VGet(1.0f, 1.0f, 1.0f));

    MV1SetUseZBuffer(model, true);
    MV1SetWriteZBuffer(model,true);

    ChangeAnimation(0);
}

void Player::ChangeAnimation(int anim_id)
{
    if (MV1GetAttachAnim(model, 0) == anim_id)
    {
        return;
    }
    MV1DetachAnim(model, 0);

    int attachIndex = MV1AttachAnim(model, anim_id);
    anim_time = MV1GetAnimTotalTime(model, anim_id);
    anim_timer = 0.0f;
}

void Player::SetGridPos(int gx, int gz) 
{ 
    const float TILE_SIZE = 16.0f; 
    pos.x = gx * TILE_SIZE + TILE_SIZE / 2; 
    pos.z = gz * TILE_SIZE + TILE_SIZE / 2; 
    pos.y = 5.0f; MV1SetPosition(model, pos); 
}

void Player::SetStage(Stage* stage_)
{
    stage = stage_;
}

void Player::Update()
{
    Move();

    // アニメーションを進める
    anim_timer += 1.0f;
    // ループ
    if (anim_timer >= anim_time)
    {
        anim_timer = 1.0f;
    }

    // モデルに反映
    MV1SetAttachAnimTime(model, 0, anim_timer);
}

void Player::Move()
{

    VECTOR move = VGet(0.0f, 0.0f, 0.0f);
    float speed = moveSpeed;

    if (CheckHitKey(KEY_INPUT_LSHIFT))
    {
        speed += dashSpeed;
    }

    if (CheckHitKey(KEY_INPUT_W))
    {
        move.z -= 1.0f;
    }
        
    if (CheckHitKey(KEY_INPUT_S))
    {
        move.z += 1.0f;
    }
        
    if (CheckHitKey(KEY_INPUT_A))
    {
        move.x += 1.0f;
    }
        
    if (CheckHitKey(KEY_INPUT_D))
    {
        move.x -= 1.0f;
    }

    bool isMoving = (move.x != 0.0f || move.z != 0.0f);

    if (isMoving && isGround)
    {
        ChangeAnimation(1);
    }
    else if (isGround)
    {
        ChangeAnimation(0);
    }

    VECTOR nextPos = pos;
    nextPos.x += move.x * speed;
    nextPos.z += move.z * speed;

    if (!stage || stage->CanEnter(nextPos))
    {
        pos = nextPos;
    }

    if (isMoving)
    {
        angleY = atan2(move.x, -move.z);
    }

    MV1SetRotationXYZ(model, VGet(0.0f, -angleY , 0.0f));
    MV1SetPosition(model, pos);
}

void Player::Draw()
{
    MV1DrawModel(model);
}

void Player::DrawHitBox()
{
    VECTOR minPos = VSub(pos, size);
    VECTOR maxPos = VAdd(pos, size);

    DrawCube3D(
        minPos,
        maxPos,
        GetColor(255, 255, 255),
        GetColor(255, 255, 255),
        FALSE
    );
}
