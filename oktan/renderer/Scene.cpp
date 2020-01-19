#include "Scene.h"
#include <oktan/platform/opengl/OGLScene.h>

namespace oktan
{
	Scene* oktan::Scene::Create(DrawPrimitives primitive)
	{
#if OK_OGL_ENABLED
		return new OGLScene(primitive);
#else
		return nullptr;
#endif
	}
}