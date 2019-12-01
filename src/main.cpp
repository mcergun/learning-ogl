#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Shader.h>
#include <Texture.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
		-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // bl
		 0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.1f,   1.0f, 0.0f, // br
		-0.5f,  0.5f, 0.0f,   0.5f, 0.5f, 0.0f,   0.0f, 1.0f, // tl
		 0.5f,  0.5f, 0.0f,   0.0f, 0.5f, 0.5f,   1.0f, 1.0f, // tr
	};

	unsigned int indices[] = {
		0, 1, 2, // first rectangle with bl, br, tl
		2, 3, 1, // second rectangle with tl, tr, br
	};

	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans = glm::mat4(1.0f);
	vec = trans * vec;
	std::cout << vec.x << vec.y << vec.z << vec.w << std::endl;

	Shader shader("shaders/simplevertex.glsl", "shaders/simplefragment.glsl");

	Texture tex1("textures/container.jpg", Texture_2D, Color_RGB);
	tex1.Bind();

	Texture tex2("textures/awesomeface.png", Texture_2D, Color_RGBA);
	tex2.Bind();

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

	while(!glfwWindowShouldClose(win))
	{
		trans = glm::rotate(trans, glm::radians(1.0f), glm::vec3(0.5f, 0.0f, 0.5f));
		// handle input
		ProcessInput(win);
		// handle rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Texture::Activate(0);
		tex1.Bind();
		Texture::Activate(1);
		tex2.Bind();
		shader.SetUniform("transform", trans);

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// check events and swap the buffers
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
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