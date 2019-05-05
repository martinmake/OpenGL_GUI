#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define FATAL_ERROR(str) { fprintf(stderr, "FATAL_ERROR at: %s\n", str); glfwTerminate(); exit(1); }

static void glClearError()
{
	while (glGetError() != GL_NO_ERROR)
		;
}

static void glCheckError()
{
	while (GLenum error = glGetError())
		fprintf(stderr, "[-] GL_ERROR: ( %d / %#0x )\n", error, error);
}

static unsigned int compile_shader(unsigned int type, const std::string& source)
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

static unsigned int create_shader(const std::string& vertex_shader, const std::string& fragment_shader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
	unsigned int fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main(void) {
	GLFWwindow* window;

	// init GLFW lib
	if (!glfwInit())
		FATAL_ERROR("GLFW init");

	// create a windowed mode window and its OpenGl context
	window = glfwCreateWindow(640, 480, "Visualization Window", NULL, NULL);
	if (!window)
		FATAL_ERROR("GLFW create_window");

	// make the window's context current
	glfwMakeContextCurrent(window);

	// init GLEW lib
	if (glewInit() != GLEW_OK)
		FATAL_ERROR("GLEW init");

	// generate one buffer (return descriptor)
	unsigned int buffer;
	glGenBuffers(1, &buffer);

	// select buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	float positions[3][2] =  {
		{ -0.5, -0.5 },
		{  0.5, -0.5 },
		{  0,    0.5 }
	};

	// allocate memory on vram for buffer for positions and fill it up
	glBufferData(GL_ARRAY_BUFFER, 3 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

	// enable attribute index 0 of buffer
	glEnableVertexAttribArray(0);

	// tell OpenGL what data is in the buffer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	std::string vertext_shader =
		"#version 130\n"
		"\n"
		"in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";

	std::string fragment_shader =
		"#version 130\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
		"}\n";

	unsigned int shader_program = create_shader(vertext_shader, fragment_shader);
	glUseProgram(shader_program);

	float velocity = 0.01;
	// loop until user closes the window
	while (!glfwWindowShouldClose(window)) {
		// render here
		glClear(GL_COLOR_BUFFER_BIT);

		// draw 3 triangles from index 0
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// swap front and back buffers
		glfwSwapBuffers(window);

		// poll for and process events
		glfwPollEvents();
	}

	glDeleteProgram(shader_program);
	glfwTerminate();

	return 0;
}
