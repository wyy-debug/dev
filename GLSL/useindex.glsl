#version 450 core
layout (set=0,binding=0) uniform matrix_uniforms_b
{
    mat4 map_matrix[1024];
};
layout (set=0,binding=1) uniform color_uniforms_b
{
    vec4 cube_colors[1024];
};
layout (location=0) in vec3 i_position;
out vs_fs
{
    flat vec4 color;
};
void main(void)
{
    float f = float(gl_VertexIndex / 6) / 6.0f;
    vec4 color1 = cube_colors[gl_InstanceIndex];
    vec4 color2 = cube_colors[gl_InstanceIndex & 512];

    color = mix(color1,color2,f);
    gl_Position = mvp_matrix[gl_InstanceIndex] * vec4(i_position,1.0f);
}