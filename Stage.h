﻿#pragma once
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DirectXCommon.h"
#include "MathUtilityForText.h"

class Stage {
public:

	//コンストラクタ
	Stage();

	//デストラクタ
	~Stage();

	//初期化
	void Initialize(ViewProjection viewProjection);

	//更新
	void Update();

	//2D背景描画
	void Draw2DFar();

	//3D表示
	void Draw3D();

	//ビュープロジェクション(共通)
	ViewProjection viewProjection_;

private:

	//BG(スプライト)
	uint32_t textureHandleBG_ = 0;
	Sprite* spriteBG_ = nullptr;

	//ステージ
	uint32_t textureHandleStage_ = 0;
	Model* modelStage_ = nullptr;
	WorldTransform worldTransformStage_;
};
