#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#include "gldebug.h"

#include "renderer.h"

#define WINDOW_WIDTH  640.0
#define WINDOW_HEIGHT 420.0

#define MODEL_WIDTH  100.0
#define MODEL_HEIGHT 100.0

int main(void)
{

	Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "Visualization Window");
	VertexArray vao;

	float positions[] =
	{
		          0,            0, 0.0, 0.0,
		MODEL_WIDTH,            0, 1.0, 0.0,
		MODEL_WIDTH, MODEL_HEIGHT, 1.0, 1.0,
		          0, MODEL_HEIGHT, 0.0, 1.0
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

	glm::vec3 model1_translation(0.0, 0.0, 0.0);
	glm::vec3 model2_translation(0.0, 0.0, 0.0);

	glm::mat4 projection = glm::ortho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
	glm::mat4 view       = glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, 0.0));
	glm::mat4 model;
	glm::mat4 vp = projection * view;

	Texture texture1(PROJECT_TEXTURE_DIRECTORY"/arch.png", 0);
	Texture texture2(PROJECT_TEXTURE_DIRECTORY"/vim.png",  1);

	// float t = 0.0;
	// float increment = 0.01;
	while (!glfwWindowShouldClose(renderer.window()))
	{
		renderer.start_frame();

		{
			ImGui::Begin("MODEL1 TRANSLATION", nullptr);
			ImGui::SliderFloat("X", &model1_translation.x, 0.0, WINDOW_WIDTH  - MODEL_WIDTH);
			ImGui::SliderFloat("Y", &model1_translation.y, 0.0, WINDOW_HEIGHT - MODEL_HEIGHT);
			ImGui::SliderFloat("Z", &model1_translation.z, 0.0, 1.0);
			ImGui::End();
			model = glm::translate(glm::mat4(1.0), model1_translation);
			shader.set_uniform_mat4f("u_mvp", vp * model);
			shader.set_uniform_1i("u_texture", 0);
			renderer.draw(vao, ibo, shader);
		}
		{
			ImGui::Begin("MODEL2 TRANSLATION", nullptr);
			ImGui::SliderFloat("X", &model2_translation.x, 0.0, WINDOW_WIDTH  - MODEL_WIDTH);
			ImGui::SliderFloat("Y", &model2_translation.y, 0.0, WINDOW_HEIGHT - MODEL_HEIGHT);
			ImGui::SliderFloat("Z", &model2_translation.z, 0.0, 1.0);
			ImGui::End();
			model = glm::translate(glm::mat4(1.0), model2_translation);
			shader.set_uniform_mat4f("u_mvp", vp * model);
			shader.set_uniform_1i("u_texture", 1);
			renderer.draw(vao, ibo, shader);
		}
		{
			// shader.set_uniform_4f("u_color", (sin(t) + 1) / 2, 0.0, (cos(t) + 1) / 2, 1.0);
			// t += increment;
			// renderer.draw(vao, ibo, shader);
		}

		renderer.end_frame();
	}

	return 0;
}
