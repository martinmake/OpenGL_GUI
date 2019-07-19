#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#include "gldebug.h"

#include "renderer.h"
#include "tests/selector.h"

#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 420

int main(int argc, char* argv[])
{
	Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "Visualization Window");

	Test::Selector test_selector;

	if (argc > 1)
	{
		test_selector.run_test(argv[1]);
	}

	while (!glfwWindowShouldClose(renderer.window()))
	{
		renderer.start_frame();

		if (test_selector.is_test_running())
		{
			test_selector.running_test().on_update(0.0).on_render().on_imgui_render();
			if (test_selector.running_test().is_done())
				test_selector.end_test();
		}
		else
			test_selector.on_render().on_imgui_render();

		renderer.end_frame();
	}

	return 0;
}
