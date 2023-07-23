#version 450 core
layout (set = 0,binding = 0)
uniform sampler2D myTexture;
layout (set = 0,binding = 2)
uniform sampler3D myLut;
layout (set = 1,binding = 0)

uniform myTransforms
{
    mat4 transform1;
    mat3 transform2;
};
void main(void)
{
    //do nothing
}