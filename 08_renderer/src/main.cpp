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

	Renderer renderer(640, 420, "Visualization Window");
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
	while (!glfwWindowShouldClose(renderer.window()))
	{
		glCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.set_uniform4f("u_Color", (sin(t) + 1) / 2, 0.0, (cos(t) + 1) / 2, 1.0);
		renderer.draw(vao, ibo, shader);

		t += increment;

		glfwSwapBuffers(renderer.window());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
