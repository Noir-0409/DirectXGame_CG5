#include "PipelineState.h"
#include "KamataEngine.h"

using namespace KamataEngine;

void PipelineState::Create(D3D12_GRAPHICS_PIPELINE_STATE_DESC desc) {

DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	ID3D12PipelineState* graphicsPipeLineState = nullptr;
HRESULT hr = dxCommon->GetDevice()->CreateGraphicsPipelineState(&desc, IID_PPV_ARGS(&graphicsPipeLineState));
	hr;
	//assert(SUCCEEDED(hr));

pipelineState_ = graphicsPipeLineState;

}

ID3D12PipelineState* PipelineState::Get() { return pipelineState_; }

PipelineState::PipelineState() {}

PipelineState::~PipelineState() {

	if (pipelineState_) {
	
	pipelineState_->Release();
	pipelineState_ = nullptr;
	
	}

}
