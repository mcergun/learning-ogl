#include <iostream>
#include <oktan/Core.h>
#include <oktan/Version.h>
#include <oktan/renderer/Window.h>
#include <oktan/renderer/Shader.h>
#include <oktan/renderer/Texture.h>
#include <oktan/renderer/VertexArray.h>
#include <oktan/renderer/Scene.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const glm::vec3 up(0.0f, 1.0f, 0.0f);
const glm::vec3 center(0.0f, 0.0f, 0.0f);

int main(int argc, char **argv)
{
	oktan::Logger::Initialize(oktan::LoggerLevel::Info, oktan::LoggerLevel::Info);
    auto win = oktan::Window::Create(600, 480, "Title");
	win->Open();

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	glm::vec3 cubePositions[] = {
		glm::vec3( 0.0f,  0.0f,  0.0f),
		glm::vec3( 2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3( 2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3( 1.3f, -2.0f, -2.5f),
		glm::vec3( 1.5f,  2.0f, -2.5f),
		glm::vec3( 1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};


	auto vao = oktan::VertexArray::Create();
	vao->AddVertexBuffer(vertices, sizeof(vertices));
	auto blo = oktan::BufferLayout::Create({
		{oktan::BaseType::Float, 3, false},
		{oktan::BaseType::Float, 2, false},
	});

	auto shader = oktan::Shader::Create("../shaders/1.8vtx.glsl", "../shaders/1.8frg.glsl");
	auto scene = oktan::Scene::Create(oktan::DrawPrimitives::Triangles);
	int32_t slot1 = 0;
	int32_t slot2 = 1;
	auto tex1 = oktan::Texture::Create("../textures/container.jpg", oktan::TextureType::Texture_2D, oktan::ColorType::Color_RGB, slot1);
	auto tex2 = oktan::Texture::Create("../textures/awesomeface.png", oktan::TextureType::Texture_2D, oktan::ColorType::Color_RGBA, slot2);
	int i = 0;
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	float radius = 8.0f;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, radius);
	glm::mat4 view = glm::lookAt(cameraPos, center, up);
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	const int div = 2;
	const float div2 = 512;
	while (!win->ShouldClose())
	{
		scene->ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		scene->ClearColorBuffer();
		float val = sin(i++ / 24.0f) * 24;
		// model = glm::rotate(model, glm::radians(val * 15), glm::vec3(0.5f, 1.0f, 0.5f));
		shader->SetUniform("tex1", slot1);
		shader->SetUniform("tex2", slot2);
		// shader->SetUniform("model", model);
		if (i % div == 0)
		{
			cameraPos = glm::vec3(sin((float)i / div / div2) * radius, 0.0f, cos((float)i / div / div2) * radius);
			view = glm::lookAt(cameraPos, center, up);
		}
		shader->SetUniform("view", view);
		shader->SetUniform("projection", projection);
		for (uint32_t j = 0; j < sizeof(cubePositions) / sizeof(cubePositions[0]); j++)
		{
			model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[j]);
			model = glm::rotate(model, glm::radians((2 * j + 1) * val), glm::vec3(0.5f, 1.0f, 0.5f));
			shader->SetUniform("model", model);
			shader->SetUniform("view", view);
			shader->SetUniform("projection", projection);
			scene->DrawArrays(0, 36);
		}

		shader->SetUniform("model", model);
		shader->Use();
		vao->Bind();
		win->SwapBuffers();
		//glfwPollEvents();
	}

    std::cout << "hello world!" << std::endl;
}