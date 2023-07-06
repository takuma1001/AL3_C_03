#pragma once
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DirectXCommon.h"
#include "MathUtilityForText.h"

class Enemy 
{
public:
	// コンストラクタ
	Enemy();
	// デストラクタ
	~Enemy();
	// 初期化
	void Initialize(ViewProjection viewProjection);
	// 更新
	void Update();
	// 3D背景描画
	void Draw3D();
	// 移動
	void Move();
	//発射
	void Born();

private:
	// ビュープロジェクション（共通）
	ViewProjection viewProjection_;

	// プレイヤー
	uint32_t textureHandleEnemy_ = 0;
	Model* modelEnemy_ = nullptr;
	WorldTransform worldTransformEnemy_;
    
	//フラグ
	bool AliveFlag = false;
};
