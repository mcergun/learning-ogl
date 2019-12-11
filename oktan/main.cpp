#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Shader.h>
#include <Texture.h>
#include <Drawer.h>

constexpr int WIN_WID = 800;
constexpr int WIN_HEI = 600;
constexpr float POSVAL = 0.5f;
constexpr float NEGVAL = -0.5f;

// callback for window resizes
void cbFrameBufferSize(GLFWwindow *win, int wid, int hei);
void ProcessInput(GLFWwindow *win);

glm::mat4 model = glm::mat4(1.0f);
glm::mat4 view = glm::mat4(1.0f);
glm::mat4 projection = glm::mat4(1.0f);

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
	glfwSetFramebufferSizeCallback(win, cbFrameBufferSize);
	glfwMakeContextCurrent(win);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Another nice fail" << std::endl;
		return -2;
	}

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

	Shader shader("shaders/simplevertex.glsl", "shaders/simplefragment.glsl");

	Texture tex1("textures/container.jpg", Texture_2D, Color_RGB);
	tex1.Bind();

	Texture tex2("textures/awesomeface.png", Texture_2D, Color_RGBA);
	tex2.Bind();

	Drawer drawer;
	drawer.AddVertexArray();
	drawer.BindVertexArray();
	drawer.AddVertexBuffer(vertices, sizeof(vertices), 5 * sizeof(float));
	drawer.BindVertexBuffer();

	drawer.AddVertexAttribute(0, DrawerType_Float, 3, false, 5 * sizeof(float), 0);
	drawer.AddVertexAttribute(1, DrawerType_Float, 2, false, 5 * sizeof(float), 3 * sizeof(float));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	shader.Use();
	shader.SetUniform("texture1", 0);
	shader.SetUniform("texture2", 1);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)WIN_WID / WIN_HEI, 0.1f, 100.0f);

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

	shader.SetUniform("model", model);
	shader.SetUniform("view", view);
	shader.SetUniform("projection", projection);

	glEnable(GL_DEPTH_TEST);
	static float lastAngle = 0.0f;
	while(!glfwWindowShouldClose(win))
	{
		ProcessInput(win);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Texture::Activate(0);
		tex1.Bind();
		Texture::Activate(1);
		tex2.Bind();

		drawer.BindVertexArray(0);
		glm::mat4 baseModel = glm::mat4(1.0f);
		lastAngle += 0.2f;
		for (size_t i = 0; i < sizeof(cubePositions) / sizeof(cubePositions[0]); i++)
		{
			model = glm::translate(baseModel, cubePositions[i]);
			model = glm::rotate(model, glm::radians(lastAngle * 2 *(i + 1)), glm::vec3(0.5f, 1.0f, 0.0f));
			shader.SetUniform("view", view);
			shader.SetUniform("model", model);
			drawer.DrawArrays();
		}
		// check events and swap the buffers
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	drawer.DeleteVertexArrays();
	drawer.DeleteVertexBuffers();
	drawer.DeleteIndexBuffers();
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
	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.05f));
	}
	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -0.05f));
	}
	if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(-0.05f, 0.0f, -0.0f));
	}
	if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(0.05f, 0.0f, 0.0f));
	}
}