#include "Shader.h"
#include <cassert>
#include <d3dcompiler.h>

void Shader::Load(const std::wstring& filePath, const std::wstring& shaderModel) {

	ID3DBlob* shaderBlob = nullptr;
	ID3DBlob* errorBlob = nullptr;

	HRESULT hr = D3DCompileFromFile(

	    filePath.c_str(), // シェーダファイル名
	    nullptr,
	    D3D_COMPILE_STANDARD_FILE_INCLUDE,               // インクルード可能にする
	    "main", shaderModel.c_str(),                     // エントリーポイント名、シェーダモデル指定
	    D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // デバッグ用設定
	    0, &shaderBlob, &errorBlob);

	// エラーが発生
	if (FAILED(hr)) {

		if (errorBlob) {

			OutputDebugStringA(reinterpret_cast<char*>(errorBlob->GetBufferPointer()));
			errorBlob->Release();
		}

		assert(false);
	}

	// 生成したshaderBlobを取っておく
	blob_ = shaderBlob;
}

ID3DBlob* Shader::GetBlob() { return blob_; }

Shader::Shader() {}

Shader::~Shader() {

	if (blob_ != nullptr) {

		blob_->Release();
		blob_ = nullptr;
	}
}