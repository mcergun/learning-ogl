#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shaderloader.h>

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
		// first triangle
		-0.5f, -0.5f, 0.0f, // bottom left
		 0.5f, -0.5f, 0.0f, // bottom right
		-0.5f,  0.5f, 0.0f, // top left
		// second triangle
		-0.5f,  0.5f, 0.0f, // top left
		 0.5f,  0.5f, 0.0f, // top right
		 0.5f, -0.5f, 0.0f, // bottom right
	};

	auto vertexShader = getShader("shaders/simplevertex.shader");
	auto fragShader = getShader("shaders/simplefragment.shader");

	const char * vertexShaderPtr = vertexShader.c_str();
	unsigned int vxsid = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vxsid, 1, &vertexShaderPtr, NULL);
	glCompileShader(vxsid);

	int success = 0;
	glGetShaderiv(vxsid, GL_COMPILE_STATUS, &success);

	if (success)
	{
		std::cout << "VertexShader compiled successfully" << std::endl;
	}
	else
	{
		char infoLog[512] = {0};
		glGetShaderInfoLog(vxsid, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}
	const char * fragShaderPtr = fragShader.c_str();
	unsigned int fgmsid = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fgmsid, 1, &fragShaderPtr, NULL);
	glCompileShader(fgmsid);
	
	glGetShaderiv(fgmsid, GL_COMPILE_STATUS, &success);

	if (success)
	{
		std::cout << "FragmentShader compiled successfully" << std::endl;
	}
	else
	{
		char infoLog[512] = {0};
		glGetShaderInfoLog(fgmsid, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}

	unsigned int sp;
	sp = glCreateProgram();

	glAttachShader(sp, vxsid);
	glAttachShader(sp, fgmsid);
	glLinkProgram(sp);
	glGetProgramiv(sp, GL_LINK_STATUS, &success);
	if (success)
	{
		std::cout << "ShaderProgram linked successfully" << std::endl;
	}
	else
	{
		char infoLog[512] = {0};
		glGetProgramInfoLog(sp, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}
	glDeleteShader(vxsid);
	glDeleteShader(fgmsid);

	unsigned int vao;
	unsigned int vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	// Unbind vertex buffer object
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind vertex array object
	glBindVertexArray(0);

	while(!glfwWindowShouldClose(win))
	{
		// handle input
		ProcessInput(win);
		// handle rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(sp);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 6);
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