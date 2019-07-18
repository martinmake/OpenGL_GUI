#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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

	float positions[] =
	{
		-0.5, -0.5, 0.0, 0.0,
		 0.5, -0.5, 1.0, 0.0,
		 0.5,  0.5, 1.0, 1.0,
		-0.5,  0.5, 0.0, 1.0
	};
	VertexBuffer vbo(positions, 4 * 4 * sizeof(float));

	VertexBufferLayout vbl;
	vbl.push<float>(2);
	vbl.push<float>(2);

	vao.add_buffer(vbo, vbl);

	unsigned int indices[2 * 3] =
	{
		0, 1, 2,
		2, 3, 0
	};
	IndexBuffer ibo(indices, 2 * 3);

	Shader shader(PROJECT_SHADER_DIRECTORY"/basic.shader");

	glm::mat4 proj = glm::ortho(-2.0, 2.0, -1.5, 1.5);
	shader.set_uniform_mat4f("u_mvp", proj);

	Texture texture(PROJECT_TEXTURE_DIRECTORY"/arch.png");
	texture.bind();
	shader.set_uniform_1i("u_texture", 0);

	float t = 0.0;
	float increment = 0.01;
	while (!glfwWindowShouldClose(renderer.window()))
	{
		glCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.set_uniform_4f("u_color", (sin(t) + 1) / 2, 0.0, (cos(t) + 1) / 2, 1.0);
		renderer.draw(vao, ibo, shader);

		t += increment;

		glfwSwapBuffers(renderer.window());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
