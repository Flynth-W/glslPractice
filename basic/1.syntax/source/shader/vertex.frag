#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 vertexColor;


out vec4 interpolatedColor;

uniform mat4 ProjectModelView;


void main()
{
  gl_Position =  aPos ;
  interpolatedColor = vertexColor ;   

}
