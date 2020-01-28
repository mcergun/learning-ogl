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
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	uint32_t indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	auto vao = oktan::VertexArray::Create();
	vao->AddVertexBuffer(vertices, sizeof(vertices));
	vao->AddIndexBuffer(indices, sizeof(indices));
	auto blo = oktan::BufferLayout::Create({
		{oktan::BaseType::Float, 3, false},
		{oktan::BaseType::Float, 3, false},
		{oktan::BaseType::Float, 2, false},
	});

	auto shader = oktan::Shader::Create("../shaders/1.6vtx.glsl", "../shaders/1.6frg.glsl");
	auto scene = oktan::Scene::Create(oktan::DrawPrimitives::Triangles);
	uint32_t slot1 = 0;
	uint32_t slot2 = 1;
	auto tex1 = oktan::Texture::Create("../textures/wall.jpg", oktan::TextureType::Texture_2D, oktan::ColorType::Color_RGB, slot1);
	auto tex2 = oktan::Texture::Create("../textures/awesomeface.png", oktan::TextureType::Texture_2D, oktan::ColorType::Color_RGBA, slot2);
	int i = 0;
	while (!win->ShouldClose())
	{
		scene->ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		scene->ClearColorBuffer();
		float val = sin(i++ / 72.0f) / 2;
		shader->SetUniform("xOffset", val);
		if (val > 0)
		{
			tex1->Assign(slot1);
		}
		else
		{
			tex2->Assign(slot1);
		}
		shader->SetUniform("tex1", slot1);
		shader->Use();
		vao->Bind();
		scene->DrawElements(0, 6, 0);
		win->SwapBuffers();
		//glfwPollEvents();
	}

    std::cout << "hello world!" << std::endl;
}