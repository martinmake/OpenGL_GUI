#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#include "gldebug.h"

#include "renderer.h"

#define WINDOW_WIDTH  640.0
#define WINDOW_HEIGHT 420.0

int main(void)
{

	Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "Visualization Window");
	VertexArray vao;

	float positions[] =
	{
		  0,   0, 0.0, 0.0,
		100,   0, 1.0, 0.0,
		100, 100, 1.0, 1.0,
		  0, 100, 0.0, 1.0
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

	glm::mat4 projection = glm::ortho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
	glm::mat4 view       = glm::translate(glm::mat4(1.0), glm::vec3(+100.0, + 0.0, +0.0));
	glm::mat4 model      = glm::translate(glm::mat4(1.0), glm::vec3(+  0.0, +50.0, +0.0));
	glm::mat4 mvp = projection * view * model;
	shader.set_uniform_mat4f("u_mvp", mvp);

	Texture texture(PROJECT_TEXTURE_DIRECTORY"/arch.png");
	texture.bind();
	shader.set_uniform_1i("u_texture", 0);

	// float t = 0.0;
	// float increment = 0.01;
	while (!glfwWindowShouldClose(renderer.window()))
	{
		renderer.start_frame();

		// shader.set_uniform_4f("u_color", (sin(t) + 1) / 2, 0.0, (cos(t) + 1) / 2, 1.0);
		renderer.draw(vao, ibo, shader);

		// t += increment;

		ImGui::Begin("SAMPLE WINDOW", nullptr);
		ImGui::Text("SAMPLE TEXT");
		ImGui::End();

		renderer.end_frame();
	}

	return 0;
}
