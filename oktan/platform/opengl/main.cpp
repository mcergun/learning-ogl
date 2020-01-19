#include <iostream>
#include <oktan/Core.h>
#include <oktan/Version.h>
#include <oktan/renderer/Window.h>
#include <oktan/renderer/Shader.h>
#include <oktan/renderer/Texture.h>
#include <oktan/renderer/VertexArray.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char **argv)
{
	oktan::Logger::Initialize(oktan::LoggerLevel::Trace, oktan::LoggerLevel::Trace);
    auto win = oktan::Window::Create(600, 480, "Title");
	win->Open();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
	};

	auto vao = oktan::VertexArray::Create();
	vao->AddVertexBuffer(vertices, sizeof(vertices));
	auto blo = oktan::BufferLayout::Create({
		{oktan::BaseType::Float, 3, false}
	});

	auto shader = oktan::Shader::Create("shaders/1.4vtx.glsl", "shaders/1.4frg.glsl");

	while (!win->ShouldClose())
	{
		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader->Use();
		vao->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// glBindVertexArray(0); // no need to unbind it every time 

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		win->SwapBuffers();
		//glfwPollEvents();
	}

    std::cout << "hello world!" << std::endl;
}