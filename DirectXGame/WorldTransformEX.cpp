#include "WorldTransformEX.h"

using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

void WorldTransformEX::UpdateMatrix() {

	//World変換行列を計算し、matworld_に格納する
	matWorld_ = MakeAffinMatrix();

	//定数バッファへの転送する
	TransferMatrix();

}

KamataEngine::Matrix4x4 WorldTransformEX::MakeAffinMatrix() { 

	//Scale Matrix
	Matrix4x4 matScale = MakeScaleMatrix(scale_);

	//Rotation Matrix
	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateYMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateZMatrix(rotation_.z);
	Matrix4x4 matRot = matRotZ * matRotX * matRotY;

	//Translate Matrix
	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);

	//World Matrix
	Matrix4x4 matWorld = matScale * matRot * matTrans;

	return matWorld;
	

}
