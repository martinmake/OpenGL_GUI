#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#define FATAL_ERROR(str) { fprintf(stderr, "FATAL_ERROR at: %s\n", str); glfwTerminate(); exit(1); }

int main(void)
{
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

	// loop until user closes the window
	while (!glfwWindowShouldClose(window)) {
		// render here
		glClear(GL_COLOR_BUFFER_BIT);

		// legaci OpenGL code (Dont use in production!)
		glBegin(GL_TRIANGLES);
		glVertex2f(0, 0);
		glVertex2f(1, 0);
		glVertex2f(0.5, 1);
		glEnd();

		// swap front and back buffers
		glfwSwapBuffers(window);

		// poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
