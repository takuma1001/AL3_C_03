﻿#pragma once

#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DirectXCommon.h"
#include "MathUtilityForText.h"
#include "Input.h"

//プレイヤー
class Player
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();
	//初期化
	void Initialize(ViewProjection viewProjection);
	//更新
	void Update();
	//3D背景描画
	void Draw3D();
	//X座標の獲得
	float GetX() { return worldTransformPlayer_.translation_.x; }
	// Y座標の獲得
	float GetY() { return worldTransformPlayer_.translation_.y; }
	// Z座標の獲得
	float GetZ() { return worldTransformPlayer_.translation_.z; }

private:
	//ビュープロジェクション（共通）
	ViewProjection viewProjection_;

    //プレイヤー
	uint32_t textureHandlePlayer_ = 0;
	Model* modelPlayer_ = nullptr;
	WorldTransform worldTransformPlayer_;

	//インプットクラス
	Input* input_ = nullptr;
};


