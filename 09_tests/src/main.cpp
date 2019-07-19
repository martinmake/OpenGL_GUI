#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#include "gldebug.h"

#include "renderer.h"

#include "tests/clear_color.h"

#define WINDOW_WIDTH  640.0
#define WINDOW_HEIGHT 420.0

int main(void)
{

	Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "Visualization Window");

	Test::Base tests[] =
	{
		Test::ClearColor()
	};

	while (!glfwWindowShouldClose(renderer.window()))
	{
		renderer.start_frame();

		for (Test::Base& test : tests)
		{
			test.on_update(0.0);
			test.on_render();
			test.on_imgui_render();
		}

		renderer.end_frame();
	}

	return 0;
}
