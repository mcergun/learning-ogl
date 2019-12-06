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
	glfwMakeContextCurrent(win);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Another nice fail" << std::endl;
		return -2;
	}

	float vertices[] = {
		-0.6f, -0.6f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // bl
		 0.6f, -0.6f, 0.0f,   0.0f, 0.0f, 0.1f,   1.0f, 0.0f, // br
		-0.6f,  0.6f, 0.0f,   0.5f, 0.5f, 0.0f,   0.0f, 1.0f, // tl
		 0.6f,  0.6f, 0.0f,   0.0f, 0.5f, 0.5f,   1.0f, 1.0f, // tr
	};

	float vertices2[] = {
		-0.6f, -0.6f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // bl
		 0.6f, -0.6f, 0.0f,   0.0f, 0.0f, 0.1f,   1.0f, 0.0f, // br
		-0.6f,  0.6f, 0.0f,   0.5f, 0.5f, 0.0f,   0.0f, 1.0f, // tl
		 0.6f,  0.6f, 0.0f,   0.0f, 0.5f, 0.5f,   1.0f, 1.0f, // tr
	};

	unsigned int indices[] = {
		0, 1, 2, // first rectangle with bl, br, tl
		2, 3, 1, // second rectangle with tl, tr, br
	};


	Shader shader("shaders/simplevertex.glsl", "shaders/simplefragment.glsl");

	Texture tex1("textures/container.jpg", Texture_2D, Color_RGB);
	tex1.Bind();

	Texture tex2("textures/awesomeface.png", Texture_2D, Color_RGBA);
	tex2.Bind();

	Drawer drawer;
	drawer.AddVertexArray();
	drawer.BindVertexArray();
	drawer.AddVertexBuffer(vertices, sizeof(vertices));
	drawer.BindVertexBuffer();
	drawer.AddIndiceBuffer(indices, sizeof(indices));
	drawer.BindIndiceBuffer();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	// Unbind vertex buffer object
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind element buffer object
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// Unbind vertex array object
	glBindVertexArray(0);

	shader.Use();
	shader.SetUniform("texture1", 0);
	shader.SetUniform("texture2", 1);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)WIN_WID / WIN_HEI, 0.1f, 100.0f);
	// trans = (projection * view) * model;

	shader.SetUniform("model", model);
	shader.SetUniform("view", view);
	shader.SetUniform("projection", projection);

	int counter = 0;
	while(!glfwWindowShouldClose(win))
	{
		// if (counter++ % 20 < 10)
		// {
		// 	trans = glm::translate(trans, glm::vec3(0.005f, 0.005f, 0.005f));
		// }
		// else
		// {
		// 	trans = glm::translate(trans, glm::vec3(-0.005f, -0.005f, -0.005f));
		// }
		// trans = glm::rotate(trans, glm::radians(1.0f), glm::vec3(0.5f, 0.0f, 0.5f));
		// handle input
		ProcessInput(win);
		// handle rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Texture::Activate(0);
		tex1.Bind();
		Texture::Activate(1);
		tex2.Bind();

		shader.SetUniform("view", view);
		drawer.BindVertexArray(0);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// check events and swap the buffers
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	drawer.DeleteVertexArrays();
	drawer.DeleteVertexBuffers();
	drawer.DeleteIndiceBuffers();
	glfwTerminate();

	std::cout << "Hello world!" << std::endl;
	return 0;
}

void cbFrameBufferSize(GLFWwindow *win, int wid, int hei)
{
	// update viewport scalings
	// glViewport(0, 0, wid, hei);
}

void ProcessInput(GLFWwindow *win)
{
	if(glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(win, true);
	}
	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.1f));
	}
	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -0.1f));
	}
	if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(-0.1f, 0.0f, -0.0f));
	}
	if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		view = glm::translate(view, glm::vec3(0.1f, 0.0f, 0.0f));
	}
}