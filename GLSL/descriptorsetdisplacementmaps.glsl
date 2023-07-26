#version 450 core
void main(void)
{
    float x = float(gl_VertexIndex & 1) - 0.5f;
    float y = float(gl_VertexIndex & 2) * 0.5f - 0.5f;
    gl_Position = vec4(x,y,0.0f,1.0f);
}