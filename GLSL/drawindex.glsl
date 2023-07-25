#version 450 core
//启用GL_ARB_shader_draw_parameters扩展
#extension GL_ARB_shader_draw_parameters : require
layout(location = 0) in vec3 position_3;
layout(set = 0, binding = 0) uniform FRAME_DATA
{
    mat4 view_matrix;
    mat4 proj_matrix;
    mat4 viewproj_matrix;
};
layout (set = 0,binding = 1) readonly buffer OBJECT_TRANSFORMS
{
    mat4 model_matrix[];
};
void main(void)
{
    //将输入顶点扩展至vec4
    vec4 position = vec4(position_3,1,0);
    
    //计算每个对象的模型-视图矩阵
    mar4 mv_matrix = view_matrix * model_matrix[gl_DrawIDARB];
    //使用全局的投影变化矩阵输出顶点
    gl_Position = proj_matrix * P;
}