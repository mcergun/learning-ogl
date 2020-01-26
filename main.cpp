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
	oktan::Logger::Initialize(oktan::LoggerLevel::Info, oktan::LoggerLevel::Info);
    auto win = oktan::Window::Create(600, 480, "Title");
	win->Open();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f,
	};

	auto vao = oktan::VertexArray::Create();
	vao->AddVertexBuffer(vertices, sizeof(vertices));
	auto blo = oktan::BufferLayout::Create({
		{oktan::BaseType::Float, 3, false},
		{oktan::BaseType::Float, 3, false}
	});

	auto shader = oktan::Shader::Create("shaders/1.4vtx.glsl", "shaders/1.4frg.glsl");
	auto scene = oktan::Scene::Create(oktan::DrawPrimitives::Triangles);

	int i = 0;
	while (!win->ShouldClose())
	{
		scene->ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		scene->ClearColorBuffer();
		float val = sin(i++ / 48.0f) / 2;
		shader->SetUniform("xOffset", val);
		shader->Use();
		vao->Bind();
		scene->DrawArrays(0, 3);
		win->SwapBuffers();
		//glfwPollEvents();
	}

    std::cout << "hello world!" << std::endl;
}