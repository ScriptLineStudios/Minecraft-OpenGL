#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>

#include "block.h"
#include "camera.h"

//#include<stb/stb_image.h> 
#define GLSL(src) "#version 330 core\n" #src
// Vertex Shader source code




int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	Block blocks[100] = {};
	for (int i = 0; i < 100; i++){
		blocks[i] = create_buffers();
	}

    float rotation = 0.0f;
    double prevTime = glfwGetTime();

	glfwSwapInterval(1);

	glEnable(GL_DEPTH_TEST);


	GLuint indices[] =
	{
		0, 1, 2,
		2, 3, 0,
		1, 5, 6,
		6, 2, 1,
		7, 6, 5,
		5, 4, 7,
		4, 0, 3,
		3, 7, 4,
		4, 5, 1,
		1, 0, 4,
		3, 2, 6,
		6, 7, 3
	};

	Camera camera;


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4 view;
        glm_mat4_identity(view);
        mat4 proj;
        glm_mat4_identity(proj);

    	glm_translate(view, (vec3){camera.x, camera.y, camera.z});
        glm_perspective(glm_rad(45.0f), (float)(800/800), 0.1f, 100.0f, proj);

		handle_movement(&camera, window);

		for (int i = 0; i < 100; i++){
			glm_mat4_identity(blocks[i].model);

			glm_translate(blocks[i].model, (vec3){(float)i*4, 0.0f, 0.0f});

			glUseProgram(blocks[i].shaderProgram);
			
			int modelLoc = glGetUniformLocation(blocks[i].shaderProgram, "model");
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (const GLfloat *)blocks[i].model);
			int viewLoc = glGetUniformLocation(blocks[i].shaderProgram, "view");
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (const GLfloat *)view);
			int projLoc = glGetUniformLocation(blocks[i].shaderProgram, "proj");
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, (const GLfloat *)proj);

			glBindVertexArray(blocks[i].VAO);
			glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

			/*glUseProgram(blocks[1].shaderProgram);
			
			int modelLoc2 = glGetUniformLocation(blocks[1].shaderProgram, "model");
			glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, (const GLfloat *)blocks[1].model);
			int viewLoc2 = glGetUniformLocation(blocks[1].shaderProgram, "view");
			glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, (const GLfloat *)view);
			int projLoc2 = glGetUniformLocation(blocks[1].shaderProgram, "proj");
			glUniformMatrix4fv(projLoc2, 1, GL_FALSE, (const GLfloat *)proj);

			glBindVertexArray(blocks[1].VAO);
			glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);*/
		}


		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}