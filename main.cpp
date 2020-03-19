#include <iostream>
#include <oktan/Core.h>
#include <oktan/Version.h>
#include <oktan/renderer/Window.h>
#include <oktan/renderer/Shader.h>
#include <oktan/renderer/Texture.h>
#include <oktan/renderer/VertexArray.h>
#include <oktan/renderer/Scene.h>
#include <oktan/renderer/InputHandler.h>
#include <oktan/renderer/Camera.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

float left = 8.0f;
float up = 0.0f;
oktan::OrthographicCamera camera(80.0f, 640.0f, 480.0f, 0.1f, 100.0f);

float inc1 = 0.15f;
void KeyCb(oktan::Keys k, int kc, oktan::Modifiers m, oktan::Actions a)
{
	using namespace oktan;
	// OK_APP_LOG_INFO("KEY {}", (char)kc);
	if (a == oktan::Actions::Continuous)
	{
		static int count = 0;
		if (count++ > 64)
		{
			inc1 *= 1.2f;
			count = 0;
			OK_APP_LOG_INFO("Getting faster {}", inc1);
		}
	}
	else
	{
		inc1 = 0.15f;
		OK_APP_LOG_INFO("Reset {}", inc1);
	}
	
	if (a == oktan::Actions::KeyDown || a == oktan::Actions::Continuous)
	{
		up = 0.0f;
		left = 0.0f;
		switch (k)
		{
		case Keys::Up:
			up = inc1;
			break;
		case Keys::Down:
			up = -inc1;
			break;
		case Keys::Right:
			left = inc1;
			break;
		case Keys::Left:
			left = -inc1;
			break;
		default:
			break;
		}
		// cameraPos = glm::vec3(sin(glm::radians(angle)) * radius, 0.0f,
		// 	cos(glm::radians(angle)) * radius);
		auto tar = camera.GetTarget();
		auto pos = camera.GetPosition();
		pos += glm::vec3(left, up, 0.0);
		tar += glm::vec3(left, up, 0.0);
		camera.SetPosition(pos);
		camera.SetTarget(tar);
	}
}

int main(int argc, char **argv)
{
	oktan::Logger::Initialize(oktan::LoggerLevel::Info, oktan::LoggerLevel::Info);
    auto win = oktan::Window::Create(600, 480, "Title");
	win->Open();
	auto inp = oktan::InputHandler::Create(win);
	inp->SetKeyCallback(KeyCb);

	oktan::VertexData newVertices[] = {
		{ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f},
		{ 0.5f, -0.5f, -0.5f,  1.0f, 0.0f},
		{ 0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
		{ 0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
		{ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f},
		{ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f},

		{-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
		{0.5f, -0.5f,  0.5f,  1.0f, 0.0f},
		{0.5f,  0.5f,  0.5f,  1.0f, 1.0f},
		{0.5f,  0.5f,  0.5f,  1.0f, 1.0f},
		{-0.5f,  0.5f,  0.5f,  0.0f, 1.0f},
		{-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},

		{-0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
		{-0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
		{-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
		{-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
		{-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
		{-0.5f,  0.5f,  0.5f,  1.0f, 0.0f},

		{0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
		{0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
		{0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
		{0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
		{0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
		{0.5f,  0.5f,  0.5f,  1.0f, 0.0f},

		{-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},
		{0.5f, -0.5f, -0.5f,  1.0f, 1.0f},
		{0.5f, -0.5f,  0.5f,  1.0f, 0.0f},
		{0.5f, -0.5f,  0.5f,  1.0f, 0.0f},
		{-0.5f, -0.5f,  0.5f,  0.0f, 0.0f},
		{-0.5f, -0.5f, -0.5f,  0.0f, 1.0f},

		{-0.5f,  0.5f, -0.5f,  0.0f, 1.0f},
		{0.5f,  0.5f, -0.5f,  1.0f, 1.0f},
		{0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
		{0.5f,  0.5f,  0.5f,  1.0f, 0.0f},
		{-0.5f,  0.5f,  0.5f,  0.0f, 0.0f},
		{-0.5f,  0.5f, -0.5f,  0.0f, 1.0f},
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
	vao->AddVertexBuffer(reinterpret_cast<float *>(newVertices), sizeof(newVertices));
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
	const int div = 2;
	const float div2 = 512;
	auto initPos = glm::vec3(0.0f, 0.0f, 50.0f);
	camera.SetPosition(initPos);
	while (!win->ShouldClose())
	{
		scene->ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		scene->ClearColorBuffer();
		float val = sin(i++ / 24.0f) * 24;
		shader->SetUniform("tex1", slot1);
		shader->SetUniform("tex2", slot2);
		shader->SetUniform("view", camera.GetViewMatrix());
		shader->SetUniform("projection", camera.GetProjectionMatrix());
		for (uint32_t j = 0; j < sizeof(cubePositions) / sizeof(cubePositions[0]); j++)
		{
			model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[j]);
			shader->SetUniform("model", model);
			shader->SetUniform("view", camera.GetViewMatrix());
			shader->SetUniform("projection", camera.GetProjectionMatrix());
			scene->DrawArrays(0, 36);
		}

		shader->SetUniform("model", model);
		shader->Use();
		vao->Bind();
		win->SwapBuffers();
	}

    std::cout << "hello world!" << std::endl;
}