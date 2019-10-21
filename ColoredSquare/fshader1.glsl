#version 410

// Input: interpolated vertex attribute
in vec4 v2fcolor;

// Output: fragment color (RGBA)
out vec4 myfragcolor;

void main()
{
    myfragcolor = v2fcolor;
}
