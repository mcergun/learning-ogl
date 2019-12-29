#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OGLBufferLayout.h"
#include "OGLVertexBuffer.h"
#include "OGLIndexBuffer.h"
#include <oktan/Logger.h>
#include <oktan/Version.h>

int main(int argc, char **argv)
{
	oktan::Logger::Initialize(oktan::LoggerLevel::Trace, oktan::LoggerLevel::Trace);
    // drawer.AddVertexAttribute(0, DrawerType_Float, 3, false, 5 * sizeof(float), 0);
	// drawer.AddVertexAttribute(1, DrawerType_Float, 2, false, 5 * sizeof(float), 3 * sizeof(float));
    
    glfwInit();
	OK_APP_LOG_TRACE("glfw initialized");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *win = glfwCreateWindow(600, 480, "Title", NULL, NULL);
	if (win == NULL)
	{
		std::cout << "Nice fail" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Another nice fail" << std::endl;
		return -2;
	}
	OK_APP_LOG_TRACE("glad loaded");

	OK_LOG_INFO("Oktan Started: v{}.{}.{}.{}",
		PROJECT_VERSION_MAJOR,
		PROJECT_VERSION_MINOR,
		PROJECT_VERSION_PATCH,
		PROJECT_VERSION_TWEAK);

    float vertices[] = {0.1f, 0.1f, 0.1f, 0.1f};
    auto vtx = oktan::VertexBuffer::Create(vertices, 4);
    vtx->Bind();
	delete vtx;
    std::cout << "hello world!" << std::endl;
}