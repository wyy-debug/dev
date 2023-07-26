#version 450 core
layout (vertices = 4) out;
out float o_outputData[4];
void main(void) 
{
    o_outputData[gl_InvocationId] = 19.0f;
}