#pragma once
#include "KamataEngine.h"

class WorldTransformEX : public KamataEngine::WorldTransform {

	public:
	void UpdateMatrix();

	KamataEngine::Matrix4x4 MakeAffinMatrix();

};
