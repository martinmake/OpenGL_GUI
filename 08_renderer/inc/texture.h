#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <inttypes.h>

#include "gldebug.h"

class Texture
{
	private:
		unsigned int m_renderer_id;
		std::string m_filepath;
		uint8_t* m_local_buffer;
		int m_width,
		    m_height;
		int m_bpp;

	public:
		Texture(const std::string& filepath);
		~Texture(void);

	public:
		void bind(unsigned int slot = 0) const;
		void unbind(void) const;

	// GETTERS
	public:
		int width(void) const;
		int height(void) const;
};

inline void Texture::bind(unsigned int slot) const
{
	assert(slot < 32);

	glCall(glActiveTexture(GL_TEXTURE0 + slot));
	glCall(glBindTexture(GL_TEXTURE_2D, m_renderer_id));
}

inline void Texture::unbind(void) const
{
	glCall(glBindTexture(GL_TEXTURE_2D, 0));
}

// GETTERS
inline int Texture::width(void) const
{
	return m_width;
}
inline int Texture::height(void) const
{
	return m_height;
}

#endif
