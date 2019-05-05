#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "functions.h"
#include "gldebug.h"

void inline fatal_error(char* str)
{
	fprintf(stderr, "FATAL ERROR AT: %s\n", str);
	glfwTerminate();
	exit(1);
}

int main(void) {
	GLFWwindow* window;

	// init GLFW lib
	if (!glfwInit())
		fatal_error("GLFW init");

	// create a windowed mode window and its OpenGl context
	window = glfwCreateWindow(640, 480, "Visualization Window", NULL, NULL);
	if (!window)
		fatal_error("GLFW create_window");

	// make the window's context current
	glfwMakeContextCurrent(window);

	// init GLEW lib
	if (glewInit() != GLEW_OK)
		fatal_error("GLEW init");

	float positions[4][2] = {
		{ -0.5, -0.5 },
		{  0.5, -0.5 },
		{  0.5,  0.5 },
		{ -0.5,  0.5 }
	};
	unsigned int buffer;
	glCall(glGenBuffers(1, &buffer));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	glCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW));
	glCall(glEnableVertexAttribArray(0));
	glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

	unsigned int indices[2][3] = {
		{ 0, 1, 2 },
		{ 2, 3, 0 }
	};
	unsigned int ibo;
	glCall(glGenBuffers(1, &ibo));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

	ShaderSource source = parse_shader(PROOT"/res/shaders/basic.shader");
 	unsigned int shader_program = create_shader(source.vertex, source.fragment);
 	glCall(glUseProgram(shader_program));

	// loop until user closes the window
	while (!glfwWindowShouldClose(window)) {
		// render here
		glCall(glClear(GL_COLOR_BUFFER_BIT));

		// draw 3 triangles from index 0
		glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		// swap front and back buffers
		glfwSwapBuffers(window);

		// poll for and process events
		glfwPollEvents();
	}

	glCall(glDeleteProgram(shader_program));
	glfwTerminate();

	return 0;
}
