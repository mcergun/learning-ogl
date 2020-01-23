#include <iostream>
#include <oktan/Core.h>
#include <oktan/Version.h>
#include <oktan/renderer/Window.h>
#include <oktan/renderer/Shader.h>
#include <oktan/renderer/Texture.h>
#include <oktan/renderer/VertexArray.h>
#include <oktan/renderer/Scene.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main(int argc, char **argv)
{
	using namespace oktan;

	Logger::Initialize(oktan::LoggerLevel::Trace, oktan::LoggerLevel::Trace);
    auto win = Window::Create(600, 480, "Title");
	win->Open();

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	float vertices2[] = {
	 0.4f,  0.4f, 0.0f,  // top right
	 0.4f, -0.4f, 0.0f,  // bottom right
	-0.4f, -0.4f, 0.0f,  // bottom left
	-0.4f,  0.4f, 0.0f   // top left 
	};

	uint32_t indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	auto vao = VertexArray::Create();
	vao->AddVertexBuffer(vertices, sizeof(vertices));
	vao->AddIndexBuffer(indices, sizeof(indices));
	vao->AddBufferLayout({
		{BaseType::Float, 3, false}
	});

	auto vao2 = VertexArray::Create();
	vao2->AddVertexBuffer(vertices2, sizeof(vertices2));
	vao2->AddIndexBuffer(indices, sizeof(indices));
	vao2->AddBufferLayout({
		{BaseType::Float, 3, false}
	});

	auto shader = Shader::Create("shaders/1.4vtx.glsl", "shaders/1.4frg.glsl");
	auto scene = Scene::Create(DrawPrimitives::Triangles);

	uint16_t i = 0;
	while (!win->ShouldClose())
	{
		scene->ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		scene->ClearColorBuffer();

		shader->Use();
		if ((i++ % 512) < 256)
			vao2->Bind();
		else
			vao->Bind();
		//scene->DrawArrays(0, 4);
		scene->DrawElements(0, 6, 0);
		win->SwapBuffers();
		//glfwPollEvents();
	}

    std::cout << "hello world!" << std::endl;
}