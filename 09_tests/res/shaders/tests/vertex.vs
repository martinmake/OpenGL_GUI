#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texture_coordinate;

out vec2 v_texture_coordinate;

uniform mat4 u_mvp;

void main()
{
	gl_Position = u_mvp * position;
	v_texture_coordinate = texture_coordinate;
}
