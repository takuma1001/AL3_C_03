#include "Beam.h"
#include "Player.h"

// コンストラクタ
Beam::Beam() {}
// デストラクタ
Beam::~Beam() {
	delete modelBeam_; // プレイヤー
}
// 初期化
void Beam::Initialize(ViewProjection viewProjection, Player* player) {
	// メンバ変数に代入
	viewProjection_ = viewProjection;
	player_ = player;
	textureHandleBeam_ = TextureManager::Load("beam.png");
	modelBeam_ = Model::Create();
	worldTransformBeam_.scale_ = {0.3f, 0.3f, 0.3f};
	worldTransformBeam_.Initialize();
	player_ = player;
	// インプットクラス
	input_ = Input::GetInstance();
}
void Beam::Move() {
	if (aliveFlag_==true) {
		worldTransformBeam_.rotation_.x += 0.1f;
		worldTransformBeam_.translation_.z += 1.0f;

		if (worldTransformBeam_.translation_.z > 40.0f) {
			aliveFlag_ = false;
		}
	}
}
void Beam::Born() {
	//移動
	if (input_->PushKey(DIK_SPACE)) {
		aliveFlag_ = true;
		worldTransformBeam_.translation_.x = player_->GetX();
		worldTransformBeam_.translation_.y = player_->GetY();
		worldTransformBeam_.translation_.z = player_->GetZ();
	}
}

// 更新
void Beam::Update() {
	// 変換行列を更新
	worldTransformBeam_.matWorld_ = MakeAffineMatrix(
	    worldTransformBeam_.scale_, worldTransformBeam_.rotation_,
	    worldTransformBeam_.translation_);
	// 変換行列を定数バッファに転送
	worldTransformBeam_.TransferMatrix();
	//移動
	Move();
	//発射
	Born();
}



// 3D描画
void Beam::Draw3D() {
	if (aliveFlag_ == true) {
		modelBeam_->Draw(worldTransformBeam_, viewProjection_, textureHandleBeam_);
	}
}