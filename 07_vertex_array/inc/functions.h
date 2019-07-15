#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

struct ShaderSource
{
	std::string vertex,
		    fragment;
};

extern ShaderSource parse_shader(const std::string& path);
extern unsigned int compile_shader(unsigned int type, const std::string& source);
extern unsigned int create_shader(const ShaderSource& shader_source);

#endif
