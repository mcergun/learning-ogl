#include <glad/glad.h>

#include "OGLScene.h"

namespace oktan
{
	static inline GLenum DrawPrimitiveToOGL(DrawPrimitives p)
	{
		switch (p)
		{
		case oktan::DrawPrimitives::Points:
			return GL_POINTS;
		case oktan::DrawPrimitives::Lines:
			return GL_LINES;
		case oktan::DrawPrimitives::Triangles:
			return GL_TRIANGLES;
		default:
			return GL_INVALID_ENUM;
		}
	}

	OGLScene::OGLScene(DrawPrimitives primitive) :
		Scene(primitive)
	{
		glEnable(GL_DEPTH_TEST);
	}

	void OGLScene::DrawArrays(uint32_t start, uint32_t count) const
	{
		glDrawArrays(DrawPrimitiveToOGL(m_Prim), start, count);
	}

	void OGLScene::DrawElements(uint32_t start, uint32_t count, void *ptr) const
	{
		glDrawElements(DrawPrimitiveToOGL(m_Prim), count, GL_UNSIGNED_INT, ptr);
	}

	void OGLScene::ClearColor(float r, float g, float b, float a) const
	{
		glClearColor(r, g, b, a);
	}

	void OGLScene::ClearColorBuffer() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}