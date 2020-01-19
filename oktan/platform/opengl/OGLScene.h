#ifndef _OK_OGL_SCENE_H_
#define _OK_OGL_SCENE_H_

#include <oktan/renderer/Scene.h>

namespace oktan
{
	class OGLScene : public Scene
	{
	public:
		OGLScene(DrawPrimitives primitive);
		virtual void DrawArrays(uint32_t start, uint32_t count) const override;
		virtual void DrawElements(uint32_t start, uint32_t count, void* ptr) const override;
		virtual void ClearColor(float r, float g, float b, float a) const override;
		virtual void ClearColorBuffer() const;
	};
}

#endif