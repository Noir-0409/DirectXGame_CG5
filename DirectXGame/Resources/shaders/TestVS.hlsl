struct VertexShaderOutput
{
    
    float32_t4 position : SV_POSITION;
    float2 texcoord : TEXCOORD0;
    
};

struct VertexShaderInput
{
    
    float32_t4 position : POSITION0;
    float2 texcoord : TEXCOORD0;
    
};

VertexShaderOutput main(VertexShaderInput input)
{
    
    VertexShaderOutput output;
    output.position = input.position;
    output.texcoord = input.texcoord;
    return output;
    
}