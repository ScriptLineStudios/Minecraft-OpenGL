#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>

#include "block.h"
#include "camera.h"

#define GLSL(src) "#version 330 core\n" #src

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

	Block blocks[16] = {};
	for (int i = 0; i < 16; i++){
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

		12, 13, 14,
		14, 15, 12,

		8, 9, 10,
		10, 11, 8
	};

	Camera camera;


	while (!glfwWindowShouldClose(window))
	{
		rotation += 0.1;
		glClearColor(0.07f, 0.13f, 0.17f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4 view;
        glm_mat4_identity(view);
        mat4 proj;
        glm_mat4_identity(proj);

    	glm_translate(view, (vec3){camera.x, camera.y, camera.z});
        glm_perspective(glm_rad(45.0f), (float)(800/800), 0.1f, 100.0f, proj);

		handle_movement(&camera, window);

		for (int i = 0; i < 16; i++){
			glm_mat4_identity(blocks[i].model);

			glm_rotate(blocks[i].model, glm_rad(0), (vec3){0.0f, 1.0f, 0.0f});
			glm_translate(blocks[i].model, (vec3){(float)i, 0, 0.0f});


			glUseProgram(blocks[i].shaderProgram);


			int modelLoc = glGetUniformLocation(blocks[i].shaderProgram, "model");
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (const GLfloat *)blocks[i].model);
			int viewLoc = glGetUniformLocation(blocks[i].shaderProgram, "view");
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (const GLfloat *)view);
			int projLoc = glGetUniformLocation(blocks[i].shaderProgram, "proj");
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, (const GLfloat *)proj);

		    glBindTexture(GL_TEXTURE_2D, blocks[i].texture);
			
			glBindVertexArray(blocks[i].VAO);
			glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		}


		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}