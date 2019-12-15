#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OGLBufferLayout.h"
#include "OGLVertexBuffer.h"
#include "OGLIndexBuffer.h"

int main(int argc, char **argv)
{
    // drawer.AddVertexAttribute(0, DrawerType_Float, 3, false, 5 * sizeof(float), 0);
	// drawer.AddVertexAttribute(1, DrawerType_Float, 2, false, 5 * sizeof(float), 3 * sizeof(float));
    
    glfwInit();
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

    float vertices[] = {0.1f, 0.1f, 0.1f, 0.1f};
    auto vtx = oktan::VertexBuffer::Create(vertices, 4);
    vtx->Bind();
    std::cout << "hello world!" << std::endl;
}