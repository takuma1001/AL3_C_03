#include "Enemy.h"
// コンストラクタ
Enemy::Enemy() {}
// デストラクタ
Enemy::~Enemy() {
	delete modelEnemy_; // プレイヤー
}
// 初期化
void Enemy::Initialize(ViewProjection viewProjection) {
	// メンバ変数に代入
	viewProjection_ = viewProjection;
	textureHandleEnemy_ = TextureManager::Load("enemy.png");
	modelEnemy_ = Model::Create();
	worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformEnemy_.Initialize();
}
//移動
void Enemy::Move() {
	if (AliveFlag == true) {
		worldTransformEnemy_.rotation_.x -= -0.15f;
		worldTransformEnemy_.translation_.z -= 0.5f;

		// 画面橋処理
		if (worldTransformEnemy_.translation_.z < -5.f) {
			AliveFlag = false;
		}
	}
}
//発射
void Enemy::Born() {
	if (AliveFlag == false) {
		AliveFlag = true;

		// 乱数処理
		int x = rand() % 80;
		float x2 = (float)x / 10 + -4;

		worldTransformEnemy_.translation_.x = x2;
		worldTransformEnemy_.translation_.z = 40.f;
	}
}
// 更新
void Enemy::Update() {
	Move();
	Born();
	// 変換行列を更新
	worldTransformEnemy_.matWorld_ = MakeAffineMatrix(
	    worldTransformEnemy_.scale_, worldTransformEnemy_.rotation_,
	    worldTransformEnemy_.translation_);
	// 変換行列を定数バッファに転送
	worldTransformEnemy_.TransferMatrix();
}
// 3D描画
void Enemy::Draw3D() {
	if (AliveFlag == true) {
		modelEnemy_->Draw(worldTransformEnemy_, viewProjection_, textureHandleEnemy_);
	}
}