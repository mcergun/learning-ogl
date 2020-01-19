#ifndef _OK_SCENE_H_
#define _OK_SCENE_H_

#include <oktan/Core.h>

namespace oktan
{
	enum class DrawPrimitives
	{
		Points,
		Lines,
		Triangles,
	};

	class Scene
	{
	public:
		Scene(DrawPrimitives prim) : m_Prim(prim) {}
		virtual void DrawArrays(uint32_t start, uint32_t count) const = 0;
		virtual void DrawElements(uint32_t start, uint32_t count, void *ptr) const = 0;
		virtual void ClearColor(float r, float g, float b, float a) const = 0;
		virtual void ClearColorBuffer() const = 0;

		static Scene* Create(DrawPrimitives primitive);

	protected:
		DrawPrimitives m_Prim;
	};
}

#endif