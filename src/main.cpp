#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr int WIN_WID = 800;
constexpr int WIN_HEI = 600;

// callback for window resizes
void cbFrameBufferSize(GLFWwindow *win, int wid, int hei);
void ProcessInput(GLFWwindow *win);

int main(int argc, char **argv)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Required for MAC builds
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *win = glfwCreateWindow(WIN_WID, WIN_HEI, "Title", NULL, NULL);
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

	glViewport(0, 0, WIN_WID, WIN_HEI);
	glfwSetFramebufferSizeCallback(win, cbFrameBufferSize);

	while(!glfwWindowShouldClose(win))
	{
		// handle input
		ProcessInput(win);
		// handle rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// check events and swap the buffers
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwTerminate();

	std::cout << "Hello world!" << std::endl;
	return 0;
}

void cbFrameBufferSize(GLFWwindow *win, int wid, int hei)
{
	// update viewport scalings
	glViewport(0, 0, wid, hei);
}

void ProcessInput(GLFWwindow *win)
{
	if(glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(win, true);
	}
}