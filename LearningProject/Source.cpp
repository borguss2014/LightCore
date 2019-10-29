#include <iostream>

#include "Platform/Windows/Window.h"

//std::chrono::duration<float> delta;
//
//float lastX = SCR_WIDTH / 2;
//float lastY = SCR_HEIGHT / 2;
//
//bool firstMouse = true;
//
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
////glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraFront;
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main()
{
	WindowProps window_properties;
	window_properties.title = "LightCore PRE-ALPHA";
	window_properties.width = 1920;
	window_properties.height = 1080;
	window_properties.fullscreen = false;
	window_properties.vsync = false;
	window_properties.center = true;

	Window m_Window(window_properties);

	int32_t monitorCnt = 0;
	std::cout << "Selected monitor: " << m_Window.GetMonitorName(m_Window.GetMonitor()) << std::endl;

	while (!glfwWindowShouldClose(m_Window.GetWindow()))
	{
		glClearColor(0.0f, 0.2f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Window.OnUpdate();
	}

	glfwTerminate();

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//glfwSetCursorPosCallback(window, mouse_callback);

	//// set up vertex data (and buffer(s)) and configure vertex attributes
	//// ------------------------------------------------------------------

	//float squareVertices[] = {
	//	-0.5f, -0.5f, 0.0f, // bottom left
	//	0.5f, -0.5f, 0.0f, // bottom right
	//	0.5f, 0.5f, 0.0f, // top right
	//	-0.5f, 0.5f, 0.0f // top left
	//};

	//unsigned int indices[] = {
	//	0, 3, 2,
	//	2, 1, 0
	//};

	//float vertices[] = {
	//	// positions          // normals           // texture coords
	//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	//	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
	//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	//	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	//	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
	//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	//	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
	//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	//	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	//	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	//	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	//	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	//	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
	//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	//	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	//	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
	//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	//	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
	//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	//};

	//glm::vec3 cubePositions[] = {
	//	  glm::vec3(0.0f,  -40.0f,  0.0f),
	//	  glm::vec3(0.0f,  -40.0f,  -1.0f),
	//	  glm::vec3(2.0f,  5.0f, -15.0f),
	//	  glm::vec3(-1.5f, -2.2f, -2.5f),
	//	  glm::vec3(-3.8f, -2.0f, -12.3f),
	//	  glm::vec3(2.4f, -0.4f, -3.5f),
	//	  glm::vec3(-1.7f,  3.0f, -7.5f),
	//	  glm::vec3(1.3f, -2.0f, -2.5f),
	//	  glm::vec3(1.5f,  2.0f, -2.5f),
	//	  glm::vec3(1.5f,  0.2f, -1.5f),
	//	  glm::vec3(-1.3f,  1.0f, -1.5f)
	//};

	//// build and compile our shader program
	//// ------------------------------------
	//Shader ourShader("shader.vert", "shader.frag"); // you can name your shader files however you like
	//Shader lightShader("lightShader.vert", "lightShader.frag");


	//GLuint diffuseMap = loadTexture("container2.png");
	//GLuint specularMap = loadTexture("container2_specular.png");
	//GLuint emissionMap = loadTexture("matrix.jpg");


	//glEnable(GL_DEPTH_TEST);

	//uint32_t squareVAO, squareVBO, squareEBO;

	//glGenVertexArrays(1, &squareVAO);
	//glGenBuffers(1, &squareVBO);
	//glGenBuffers(1, &squareEBO);

	//glBindVertexArray(squareVAO);

	//glBindBuffer(GL_ARRAY_BUFFER, squareVBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices), squareVertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, squareEBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	//



	//unsigned int VBO, VAO, EBO, lightVAO;

	//glGenVertexArrays(1, &VAO);
	//glGenVertexArrays(1, &lightVAO);

	//glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	//// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	//glBindVertexArray(VAO);

	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	///*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	//// position attribute
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	//// normal attribute
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);

	//// texture attribute
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	//glEnableVertexAttribArray(2);

	//// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	//// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	//glBindVertexArray(0);


	//glBindVertexArray(lightVAO);

	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//// position attribute
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	//glBindVertexArray(0);


	//glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	//glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);

	//glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);


	//std::chrono::time_point<std::chrono::steady_clock> lastFrameTime = std::chrono::high_resolution_clock::now();

	//float lastFrame = 0.0f;

	//float angle = 0.0f;

	//float translationFactor = 1.0f;
	//float newCubeYVal = cubePositions[0].y;

	//// render loop
	//// -----------
	//while (!glfwWindowShouldClose(window))
	//{
	//	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::high_resolution_clock::now();

	//	delta = start - lastFrameTime;

	//	lastFrameTime = start;

	//	float blinkVal = (glm::sin(glfwGetTime()) * 0.5 + 0.5) * 10;

	//	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	// input
	//	// -----
	//	processInput(window);

	//	// render
	//	// ------

	//	//angle += 6.0f * delta.count();

	//	

	//	ourShader.use();

	//	glm::mat4 projection;
	//	projection = glm::perspective(glm::radians(45.0f), (float)(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);

	//	unsigned int projectionLoc = glGetUniformLocation(ourShader.ID, "projection");
	//	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//	glm::mat4 view = camera.GetViewMatrix();

	//	unsigned int viewLoc = glGetUniformLocation(ourShader.ID, "view");
	//	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));



	//	unsigned int camPosLoc = glGetUniformLocation(ourShader.ID, "camPos");
	//	glUniform3fv(camPosLoc, 1, glm::value_ptr(camera.cameraPos));

	//	unsigned int timeLoc = glGetUniformLocation(ourShader.ID, "time");
	//	glUniform1f(timeLoc, glfwGetTime());


	//	unsigned int lightLoc = glGetUniformLocation(ourShader.ID, "light.position");
	//	glUniform3fv(lightLoc, 1, glm::value_ptr(camera.cameraPos));

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.direction");
	//	glUniform3fv(lightLoc, 1, glm::value_ptr(camera.cameraFront));

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.cutOff");
	//	glUniform1f(lightLoc, glm::cos(glm::radians(12.5f)));

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.outerCutOff");
	//	glUniform1f(lightLoc, glm::cos(glm::radians(17.5f)));

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.ambient");
	//	glUniform3fv(lightLoc, 1, glm::value_ptr(glm::vec3(0.2f, 0.2f, 0.2f)));

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.diffuse");
	//	glUniform3fv(lightLoc, 1, glm::value_ptr(glm::vec3(0.5f, 0.5f, 0.5f)));

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.specular");
	//	glUniform3fv(lightLoc, 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));



	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.constant");
	//	glUniform1f(lightLoc, 1.0f);

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.linear");
	//	glUniform1f(lightLoc, 0.09f);

	//	lightLoc = glGetUniformLocation(ourShader.ID, "light.quadratic");
	//	glUniform1f(lightLoc, 0.032f);



	//	unsigned int materialLoc = glGetUniformLocation(ourShader.ID, "material.diffuse");
	//	glUniform1i(materialLoc, 0);

	//	materialLoc = glGetUniformLocation(ourShader.ID, "material.specular");
	//	glUniform1i(materialLoc, 1);

	//	materialLoc = glGetUniformLocation(ourShader.ID, "material.emission");
	//	glUniform1i(materialLoc, 2);

	//	materialLoc = glGetUniformLocation(ourShader.ID, "material.shininess");
	//	glUniform1f(materialLoc, 128.0f);

	//	glActiveTexture(GL_TEXTURE0);
	//	glBindTexture(GL_TEXTURE_2D, diffuseMap);

	//	glActiveTexture(GL_TEXTURE1);
	//	glBindTexture(GL_TEXTURE_2D, specularMap);

	//	//glActiveTexture(GL_TEXTURE2);
	//	//glBindTexture(GL_TEXTURE_2D, emissionMap);

	//	glBindVertexArray(VAO);

	//	

	//	if (newCubeYVal < -10.0f)
	//	{
	//		newCubeYVal += (-10.0f - newCubeYVal) * 0.01f;
	//	}
	//	else
	//	{
	//		newCubeYVal = -10.0f;
	//	}
	//	
	//	float displacement = 1.5f;

	//	float newZ = cubePositions[0].z;

	//	for (unsigned int i = 0; i < 10; i++)
	//	{
	//		glm::mat4 model = glm::mat4(1.0f);
	//		model = glm::translate(model, glm::vec3(cubePositions[0].x, cubePositions[0].y, newZ));

	//		//float angle = 20.0f * (i+1);

	//		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));

	//		model = glm::scale(model, glm::vec3(1.0f, 20.0f, 1.0f));

	//		unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
	//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	//		// render the triangle	
	//		glDrawArrays(GL_TRIANGLES, 0, 36);
	//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	//		newZ += displacement;
	//	}

	//	
	//	
	//	lightShader.use();

	//	projectionLoc = glGetUniformLocation(lightShader.ID, "projection");
	//	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//	viewLoc = glGetUniformLocation(lightShader.ID, "view");
	//	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	//	glm::mat4 model = glm::mat4(1.0f);
	//	model = glm::translate(model, lightPos);
	//	model = glm::scale(model, glm::vec3(0.2f));

	//	unsigned int modelLoc = glGetUniformLocation(lightShader.ID, "model");
	//	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	//	unsigned int lightColorLoc = glGetUniformLocation(lightShader.ID, "lightColor");
	//	glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));

	//	glBindVertexArray(lightVAO);
	//	//glDrawArrays(GL_TRIANGLES, 0, 36);

	//	glBindVertexArray(0);

	//	glUseProgram(0);


	//	// UI
	//	glBindVertexArray(squareVAO);
	//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//	glBindVertexArray(0);

	//	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	//	// -------------------------------------------------------------------------------
	//	glfwSwapBuffers(window);
	//	glfwPollEvents();

	//	/*std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::high_resolution_clock::now();

	//	std::chrono::steady_clock::duration time = (end - start);*/

	//	//std::cout << time/std::chrono::milliseconds(1) << " ms\n";
	//	std::cout << delta.count() * 1000.0f << "ms\n";
	//}

	//// optional: de-allocate all resources once they've outlived their purpose:
	//// ------------------------------------------------------------------------
	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);

	//// glfw: terminate, clearing all previously allocated GLFW resources.
	//// ------------------------------------------------------------------
	//glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//		return;
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
//	{
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE)
//	{
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(FORWARD, delta.count());
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(BACKWARD, delta.count());
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(RIGHT, delta.count());
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(LEFT, delta.count());
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
//	{
//		camera.setSpeed(5.0f);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
//	{
//		camera.setSpeed(2.0f);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
//	{
//		glfwSwapInterval(0);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_RELEASE)
//	{
//		glfwSwapInterval(1);
//	}
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xOffset = xpos - lastX;
//	float yOffset = lastY - ypos;
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouse(xOffset, yOffset);
//}
//
//GLuint loadTexture(const char* path)
//{
//	GLuint texture;
//
//	glGenTextures(1, &texture);
//
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
//
//	GLenum format;
//
//	if (data)
//	{
//		if (nrChannels == 1)
//		{
//			format = GL_RED;
//		}
//		else if (nrChannels == 3)
//		{
//			format = GL_RGB;
//		}
//		else if (nrChannels == 4)
//		{
//			format = GL_RGBA;
//		}
//
//		glBindTexture(GL_TEXTURE_2D, texture);
//
//		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		glBindTexture(GL_TEXTURE_2D, 0);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//
//	stbi_image_free(data);
//
//	return texture;
//}