#shader vertex
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

#shader fragment
#version 330

in vec2 v_texture_coordinate;

layout(location = 0) out vec4 color;

uniform vec4 u_color;
uniform sampler2D u_texture;

void main()
{
	vec4 texture_color = texture(u_texture, v_texture_coordinate);
	color = texture_color;
}
