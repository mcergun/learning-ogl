#include <iostream>
#include <oktan/Logger.h>
#include <oktan/Version.h>
#include <oktan/renderer/Buffers.h>
#include <oktan/renderer/Window.h>
#include <oktan/renderer/Shader.h>
#include <oktan/renderer/Texture.h>

int main(int argc, char **argv)
{
	oktan::Logger::Initialize(oktan::LoggerLevel::Trace, oktan::LoggerLevel::Trace);
    // drawer.AddVertexAttribute(0, DrawerType_Float, 3, false, 5 * sizeof(float), 0);
	// drawer.AddVertexAttribute(1, DrawerType_Float, 2, false, 5 * sizeof(float), 3 * sizeof(float));
    auto win = oktan::Window::Create(600, 480, "Title");
	win->Open();

	OK_LOG_INFO("Oktan Started: v{}.{}.{}.{}",
		PROJECT_VERSION_MAJOR,
		PROJECT_VERSION_MINOR,
		PROJECT_VERSION_PATCH,
		PROJECT_VERSION_TWEAK);

	auto tex1 = oktan::Texture::Create("textures/container.jpg",
		oktan::TextureType::Texture_2D,
		oktan::ColorType::Color_RGB);
	auto tex2 = oktan::Texture::Create("textures/awesomeface.png",
		oktan::TextureType::Texture_2D,
		oktan::ColorType::Color_RGBA);

	tex1->Bind();
	tex2->Bind();

    float vertices[] = {0.1f, 0.1f, 0.1f, 0.1f};
	auto shader = oktan::Shader::Create("./shaders/simplevertex.glsl", "./shaders/simplefragment.glsl");
	shader->SetUniform("texture1", true);
	shader->SetUniform("texture1", false);
    auto vtx = oktan::VertexBuffer::Create(vertices, 4);
	auto tex = oktan::Texture::Create("./textures/wall.jpg", oktan::TextureType::Texture_2D, oktan::ColorType::Color_RGB);
    vtx->Bind();
	delete vtx;
    std::cout << "hello world!" << std::endl;
}