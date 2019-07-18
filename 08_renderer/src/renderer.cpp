#include "renderer.h"

Renderer::Renderer(int width, int height, const std::string& title)
{
	assert(glfwInit() && "GLFW init");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	assert(glewInit() == GLEW_OK && "GLEW init");

	glCall(std::cout << "[GL VERSION]   " << glGetString(GL_VERSION)                  << std::endl);
	glCall(std::cout << "[GLSL VERSION] " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl);

	glCall(glEnable(GL_BLEND));
	glCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

Renderer::~Renderer(void)
{
	glfwTerminate();
}

void Renderer::draw(const VertexArray& vertex_array, const IndexBuffer& index_buffer, const Shader& shader) const
{
	vertex_array.bind();
	index_buffer.bind();
	shader.bind();

	glCall(glDrawElements(GL_TRIANGLES, index_buffer.count(), GL_UNSIGNED_INT, nullptr));
}
