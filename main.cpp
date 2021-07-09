#include <iostream>
#include <conio.h>
#include "defines.h"
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Camera.h"
// #include "Cube.h"

int wWidth = 700, wHeight = 700;

Camera cam(glm::vec3(0.0f, 0.0f, -10.0f));

int main()
{
	GLFWwindow *window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(wWidth, wHeight, "Window", NULL, NULL);

	if (!window)
		return -1;

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return -1;

	const char *dVSS =
			"#version 330 core\n"
			"\n"
			"layout (location = 0) in vec3 aPos;\n"
			"\n"
			"uniform mat4 proj;\n"
			"uniform mat4 view;\n"
			"uniform mat4 model;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	gl_Position = proj * view * model * vec4(aPos, 1.0);\n"
			"};\n\0";

	const char *dFSS =
			"#version 330 core\n"
			"\n"
			"layout (location = 0) out vec4 color;\n"
			"\n"
			"uniform vec4 uColor;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	color = uColor;\n"
			"};\n\0";

	Shader shader(dVSS, dFSS);
	shader.setVec4(1.0f, 0.0f, 0.0f, 1.0f, "uColor");

	float vertices[] =
			{-0.5f, 0.5f, 0.5f,
			 0.5f, 0.5f, 0.5f,
			 -0.5f, -0.5f, 0.5f,
			 0.5f, -0.5f, 0.5f,

			 -0.5f, 0.5f, -0.5f,
			 0.5f, 0.5f, -0.5f,
			 -0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f};

	unsigned int indices[] =
			{0, 1, 2,
			 1, 2, 3,

			 0, 4, 6,
			 0, 6, 2,

			 1, 5, 7,
			 1, 7, 3,

			 0, 1, 4,
			 1, 4, 5,

			 2, 3, 6,
			 3, 6, 7,

			 4, 5, 6,
			 5, 6, 7};

	unsigned int va;
	glGenVertexArrays(1, &va);
	glBindVertexArray(va);
	VertexBuffer vb(24 * sizeof(float), vertices);
	IndexBuffer ib(36, indices);
	glBindVertexArray(0);

	Shader planeShader(dVSS, dFSS);
	planeShader.setVec4(1.0f, 0.8f, 0.2f, 1.0f, "uColor");

	float planeVertices[] =
			{-0.5f, 0.0f, -0.5f,
			 0.5f, 0.0f, -0.5f,
			 -0.5f, 0.0f, 0.5f,
			 0.5f, 0.0f, 0.5f};

	float tPlaneVertices[] =
			{-10.0f, 0.0f, -10.0f,
			 10.0f, 0.0f, -10.0f,
			 -10.0f, 0.0, 10.0f,
			 10.0f, 0.0f, 10.0f};

	unsigned int planeIndices[] =
			{0, 1, 2,
			 1, 2, 3};

	unsigned int planeVA;
	glGenVertexArrays(1, &planeVA);
	glBindVertexArray(planeVA);
	VertexBuffer planeVB(12 * sizeof(float), planeVertices);
	IndexBuffer planeIB(6, planeIndices);
	glBindVertexArray(0);

	glm::mat4 proj = glm::perspective(glm::radians(90.0f), (float)wWidth / (float)wHeight, 0.1f, 1000.0f);
	shader.setMat4(proj, "proj");
	planeShader.setMat4(proj, "proj");

	while (!glfwWindowShouldClose(window))
	{
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
		cam.uView();
		shader.setMat4(cam.getView(), "view");
		planeShader.setMat4(cam.getView(), "view");

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::rotate(model, (float)glfwGetTime() * 5.0f, glm::vec3(1.0f, 0.8f, 0.2f));
		shader.setMat4(model, "model");

		glm::mat4 planeModel = glm::mat4(1.0f);
		planeModel = glm::translate(planeModel, glm::vec3(0.0f, -4.0f, 0.0f));
		planeModel = glm::scale(planeModel, glm::vec3(10.0f, 0.0f, 10.0f));
		planeShader.setMat4(planeModel, "model");

		shader.Use();
		glBindVertexArray(va);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

		planeShader.Use();
		glBindVertexArray(planeVA);
		glDrawElements(GL_TRIANGLES, planeIB.GetCount(), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	_getch();
	return 0;
}
