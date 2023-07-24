layout(set=0,binding=1)
uniform my_uniform_buffer_t
{
    float foo;
    vec4 bra;
    int baz[42];
}my_uniform_buffer_;
layout(set=1,binding=2)
uniform my_storage_buffer_t
{
    int peas;
    float carrots;
    vec3 potatoes[99];
}my_storage_buffer_t;