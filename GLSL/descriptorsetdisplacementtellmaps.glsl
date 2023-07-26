#version 450 core layout(vertice = 4) out;
void main(){
    if(gl_InvocationID == 0)
    {
        gl_TessLevelInner[0] = 64.0f;
        gl_TessLevelInner[1] = 64.0f;
        gl_TesslevelOutput[0] = 64.0f
        gl_TesslevelOutput[1] = 64.0f;
        gl_TesslevelOutput[2] = 64.0f;
        gl_TesslevelOutput[3] = 64.0f;

    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}