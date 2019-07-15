#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#include "gldebug.h"

#include "renderer.h"

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

	Renderer renderer;
	VertexArray vao;

	float positions[4 * 2] =
	{
		-0.5, -0.5,
		 0.5, -0.5,
		 0.5,  0.5,
		-0.5,  0.5
	};
	VertexBuffer vbo(positions, 4 * 2 * sizeof(float));

	VertexBufferLayout vbl;
	vbl.push<float>(2);

	vao.add_buffer(vbo, vbl);

	unsigned int indices[2 * 3] =
	{
		0, 1, 2,
		2, 3, 0
	};
	IndexBuffer ibo(indices, 2 * 3);

	Shader shader(PROOT"/res/shaders/basic.shader");

	float t = 0.0;
	float increment = 0.01;
	while (!glfwWindowShouldClose(window))
	{
		glCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.set_uniform4f("u_Color", (sin(t) + 1) / 2, 0.0, (cos(t) + 1) / 2, 1.0);
		renderer.draw(vao, ibo, shader);

		t += increment;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
