#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Shader.h>

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

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bl
		-0.5f,  0.5f, 0.0f,  0.5f, 0.5f, 0.0f, // tl
		 0.5f,  0.5f, 0.0f,  0.0f, 0.5f, 0.5f, // tr
		 0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 0.1f, // br
	};

	unsigned int indices[] = {
		0, 1, 2, // first rectangle with bot-lf, top-lf, top-rt
		0, 2, 3, // second rectangle with bot-lf, top-rt, bot-rt
	};

	Shader shader("shaders/simplevertex.glsl", "shaders/simplefragment.glsl");


	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	// Unbind vertex buffer object
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind element buffer object
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// Unbind vertex array object
	glBindVertexArray(0);

	shader.Use();
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while(!glfwWindowShouldClose(win))
	{
		// handle input
		ProcessInput(win);
		// handle rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// check events and swap the buffers
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
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