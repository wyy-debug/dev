#version 450 core
layout(quads) in;
void main(void)
{
    gl_position = vec4(gl_TessCoord,1.0);
}