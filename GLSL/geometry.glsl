#version 450 core
layout (triangles) in;
layout (traingle_strip) out;
layout (max_vertices = 3) out;
void main() {
    //donothing;
}
in gl_PerVertex{
    vec4 gl_Position;
}gl_in[];
out gs_out
{
    vec4 color;
};