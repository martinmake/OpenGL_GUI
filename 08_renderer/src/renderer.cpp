#include "renderer.h"

Renderer::Renderer(void)
{
}

Renderer::~Renderer(void)
{
}

void Renderer::draw(const VertexArray& vertex_array, const IndexBuffer& index_buffer, const Shader& shader) const
{
	vertex_array.bind();
	index_buffer.bind();
	shader.bind();

	glCall(glDrawElements(GL_TRIANGLES, index_buffer.count(), GL_UNSIGNED_INT, nullptr));
}
