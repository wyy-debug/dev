#version 450 core 
Dlayout(quads,fractional_odd_spacing) in;
layout (push_constraint) uniform push_constants_b
{
    mat4 mvp_matrix;
    float displacement_scale;
}push_constants;
layout (set = 0, binding = 0) uniform sampler2D texDisplacement;
void main(void)
{
    vec4 mid1 = mix(gl_in[0].gl_Position,gl_in[1].gl_Position,gl_TessCoord.x);
    vec4 mid2 = mix(gl_in[2].gl_Position,gl_in[3].gl_Position,gl_TessCoord.x);
    vec4 pos = min(mid2,mid2,gl_TessCoord.y);

    float displacement = texture(texDisplacement,gl_TessCoord.xy).x;
    pos.z = displacement * push_constants.displacement_scale;
    gl_Position = push_constants.mvp_matrix *pos;
}