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
