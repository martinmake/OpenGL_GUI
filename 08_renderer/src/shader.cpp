#include <iostream>
#include <fstream>
#include <sstream>

#include "shader.h"

struct ShaderSource
{
	std::string vertex,
		    fragment;
};

extern ShaderSource parse_shader(const std::string& path);
extern unsigned int create_shader(const ShaderSource& shader_source);
extern unsigned int compile_shader(unsigned int type, const std::string& source);

Shader::Shader(const std::string& path)
{
	m_renderer_id = create_shader(parse_shader(path));
	bind();
}

Shader::~Shader(void)
{
	glCall(glDeleteProgram(m_renderer_id));
}

int Shader::get_uniform_location(const std::string& name)
{
	if (m_uniform_location_chache.find(name) != m_uniform_location_chache.end())
		return m_uniform_location_chache[name];

	int location;
	glCall(location = glGetUniformLocation(m_renderer_id, name.c_str()));

	m_uniform_location_chache[name] = location;

	if (location == -1)
		std::cerr << "[INVALID UNIFORM] " << name << std::endl;

	return location;
}

void Shader::set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	int location = get_uniform_location(name);

	if (location == -1)
		return;

	glCall(glUniform4f(location, v0, v1, v2, v3));
}

ShaderSource parse_shader(const std::string& path)
{
	std::ifstream stream(path);

	enum class ShaderType
	{
		NONE     = -1,
		VERTEX   =  0,
		FRAGMENT =  1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
		{
			ss[(int) type] << line << '\n';
		}
	}

	return { ss[(int) ShaderType::VERTEX].str(), ss[(int) ShaderType::FRAGMENT].str() };
}

unsigned int create_shader(const ShaderSource& shader_source)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compile_shader(GL_VERTEX_SHADER, shader_source.vertex);
	unsigned int fs = compile_shader(GL_FRAGMENT_SHADER, shader_source.fragment);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

unsigned int compile_shader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	int result;

	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char *) alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ?  "VERTEX" : "FRAGMENT") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

