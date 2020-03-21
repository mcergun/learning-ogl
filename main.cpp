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
const uint32_t WIN_WID = 960;
const uint32_t WIN_HEI = 720;
const float MV_RATE = 0.025f;
oktan::OrthographicCamera *camera = nullptr;

float inc1 = MV_RATE;
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
		inc1 = MV_RATE;
		OK_APP_LOG_INFO("Reset {}", inc1);
	}
	
	if (a == oktan::Actions::KeyDown || a == oktan::Actions::Continuous)
	{
		up = 0.0f;
		left = 0.0f;
		switch (k)
		{
		case Keys::Up:
			up = -inc1;
			break;
		case Keys::Down:
			up = inc1;
			break;
		case Keys::Right:
			left = -inc1;
			break;
		case Keys::Left:
			left = inc1;
			break;
		default:
			break;
		}
		// cameraPos = glm::vec3(sin(glm::radians(angle)) * radius, 0.0f,
		// 	cos(glm::radians(angle)) * radius);
		auto tar = camera->GetTarget();
		auto pos = camera->GetPosition();
		pos += glm::vec3(left, up, 0.0);
		tar += glm::vec3(left, up, 0.0);
		camera->SetPosition(pos);
		camera->SetTarget(tar);
	}
}

int main(int argc, char **argv)
{
	oktan::Logger::Initialize(oktan::LoggerLevel::Info, oktan::LoggerLevel::Info);
	camera = new oktan::OrthographicCamera(70.0f, WIN_WID, WIN_HEI, 0.20f, 160.0f);
    auto win = oktan::Window::Create(WIN_WID, WIN_HEI, "Title");
	win->Open();
	auto inp = oktan::InputHandler::Create(win);
	inp->SetKeyCallback(KeyCb);
	oktan::QuadData quad(-0.5f, -0.5f, 0.5f, 0.5f);
	uint32_t indices[] = {0, 1, 2, 2, 3, 0};

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
	// vao->AddVertexBuffer(reinterpret_cast<float *>(newVertices), sizeof(newVertices));
	vao->AddVertexBuffer(reinterpret_cast<float *>(&quad), sizeof(quad));
	vao->AddIndexBuffer(indices, sizeof(indices));
	auto blo = oktan::BufferLayout::Create({
		{oktan::BaseType::Float, 3, false},
		{oktan::BaseType::Float, 2, false},
	});

	auto shader = oktan::Shader::Create("../shaders/simplevertex.glsl", "../shaders/simplefragment.glsl");
	auto scene = oktan::Scene::Create(oktan::DrawPrimitives::Triangles);
	int32_t slot1 = 0;
	auto tex1 = oktan::Texture::Create("../textures/container.jpg", oktan::TextureType::Texture_2D, oktan::ColorType::Color_RGB, slot1);
	int i = 0;
	glm::mat4 model = glm::mat4(1.0f);
	const int div = 2;
	const float div2 = 512;
	auto initPos = glm::vec3(0.0f, 0.0f, 50.0f);
	camera->SetPosition(initPos);
	while (!win->ShouldClose())
	{
		scene->ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		scene->ClearColorBuffer();
		float val = sin(i++ / 24.0f) * 24;
		shader->SetUniform("tex1", slot1);
		model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[0]);
		shader->SetUniform("model", model);
		shader->SetUniform("view", camera->GetViewMatrix());
		shader->SetUniform("projection", camera->GetProjectionMatrix());
		scene->DrawElements(0, 6, 0);
		shader->Use();
		vao->Bind();
		win->SwapBuffers();
	}
	delete tex1;
	delete scene;
	delete shader;
	delete blo;
	delete vao;
	delete inp;
	delete win;
	delete camera;
    std::cout << "hello world!" << std::endl;
}