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
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.0f, 0.0f,
	};

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	auto vertexShader = getShader("shaders/simplevertex.shader");
	std::cout << vertexShader << std::endl;
	auto fragShader = getShader("shaders/simplefragment.shader");
	std::cout << fragShader << std::endl;

	unsigned int vxsid;
	const char * vertexShaderPtr = vertexShader.c_str();
	vxsid = glCreateShader(GL_VERTEX_SHADER);
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
	unsigned int fgmsid;
	glCreateShader(GL_FRAGMENT_SHADER);
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

	glUseProgram(sp);

	glDeleteShader(vxsid);
	glDeleteShader(fgmsid);

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