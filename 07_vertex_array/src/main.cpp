#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#include "functions.h"
#include "gldebug.h"

int main(void)
{
	GLFWwindow* window;

	assert(glfwInit() && "GLFW init");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(640, 480, "Visualization Window", NULL, NULL);
	assert(window && "GLFW create_window");
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	assert(glewInit() == GLEW_OK && "GLEW init");

	glCall(std::cout << "[GL VERSION]   " << glGetString(GL_VERSION)                  << std::endl);
	glCall(std::cout << "[GLSL VERSION] " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl);

	unsigned int vao;
	glCall(glGenVertexArrays(1, &vao));
	glCall(glBindVertexArray(vao));

	float positions[4][2] =
	{
		{ -0.5, -0.5 },
		{  0.5, -0.5 },
		{  0.5,  0.5 },
		{ -0.5,  0.5 }
	};
	unsigned int abo;
	glCall(glGenBuffers(1, &abo));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, abo));
	glCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW));
	glCall(glEnableVertexAttribArray(0));
	glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

	unsigned int indices[2][3] =
	{
		{ 0, 1, 2 },
		{ 2, 3, 0 }
	};
	unsigned int ibo;
	glCall(glGenBuffers(1, &ibo));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

	ShaderSource shader_source = parse_shader(PROOT"/res/shaders/basic.shader");
 	unsigned int shader_program = create_shader(shader_source);
 	glCall(glUseProgram(shader_program));

	glCall(int color_location = glGetUniformLocation(shader_program, "u_Color"));
	assert(color_location != -1);

	float t = 0.0;
	float increment = 0.01;
	while (!glfwWindowShouldClose(window))
	{
		glCall(glClear(GL_COLOR_BUFFER_BIT));

		glCall(glUniform4f(color_location, (sin(t) + 1) / 2, 0.0, (cos(t) + 1) / 2, 1.0));
		glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		t += increment;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glCall(glDeleteProgram(shader_program));
	glfwTerminate();

	return 0;
}
