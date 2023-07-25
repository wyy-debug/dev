#version 450 core
vec3 unpackA2R10G10B10_snorm(uint value)
{
    int val_signed = int(value);
    vec3 result;
    const float scale = (1.0f/512.0f);

    result.x = float(bitfieldExtract(val_signed,20,10));
    result.y = float(bitfieldExtract(val_signed,10,10));
    result.z = float(bitfieldExtract(val_signed,0,10));

    return result * scale;
}

void main(void)
{
    gl_Position = vec4(unpackA2R10G10B10_snorm(gl_VertexIndex),1.0f)
}