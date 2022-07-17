#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

#include "block.h"
#include "camera.h"
#include "chunk.h"
#include "perlin.h"
#include "world.h"



int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Minecraft 100% legitimate", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	BaseInfo basicBlockData = initialize_block_info();

    World world;
	world = GenerateWorld(basicBlockData);
	
	glfwSwapInterval(1);

	glEnable(GL_DEPTH_TEST);

	Camera camera;

	camera.x = -16;
	camera.z = -16;


	Info info;
	info.basicBlockData = basicBlockData;
	info.world = &world;

	pthread_t th;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.43f, 0.69f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS){
			pthread_t th;
			pthread_create(&th, NULL, &AddNewChunk, &info);
    	}

        mat4 view;
        glm_mat4_identity(view);
        mat4 proj;
        glm_mat4_identity(proj);

    	glm_translate(view, (vec3){camera.x, camera.y, camera.z});
        glm_perspective(glm_rad(45), (float)(800/800), 0.1f, 1000.0f, proj);

		handle_movement(&camera, window);

		glUseProgram(basicBlockData.shaderProgram);
		glBindTexture(GL_TEXTURE_2D, basicBlockData.texture);

		glBindVertexArray(basicBlockData.VAO);

		int viewLoc = glGetUniformLocation(basicBlockData.shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (const GLfloat *)view);
		int projLoc = glGetUniformLocation(basicBlockData.shaderProgram, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, (const GLfloat *)proj);

	//printf("%d %d \n", (int)floor(camera.x / 32) + 1, (int)floor(camera.z / 32) + 1);


		bool shouldGenerateChunk = true;
		for (int j = 0; j < world.numberChunks; j++){
			for (int i = 0; i < 4096; i++){
				glm_mat4_identity(world.chunks[j].blocks[i].model);

				//glm_rotate(world.chunks[j].blocks[i].model, glm_rad(camera.rotation), (vec3){0.0f, 1.0f, 0.0f});
				glm_translate(world.chunks[j].blocks[i].model, (vec3){world.chunks[j].blocks[i].x, world.chunks[j].blocks[i].y, world.chunks[j].blocks[i].z});

				int modelLoc = glGetUniformLocation(basicBlockData.shaderProgram, "model");
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (const GLfloat *)world.chunks[j].blocks[i].model);
				
				if (world.chunks[j].blocks[i].shouldRenderFront)
					glDrawRangeElements(GL_TRIANGLES, 0, 6, 6, GL_UNSIGNED_INT, (void*)(0*sizeof(unsigned int))); //FRONT 
				if (world.chunks[j].blocks[i].shouldRenderRight)
					glDrawRangeElements(GL_TRIANGLES, 6, 12, 6, GL_UNSIGNED_INT, (void*)(6*sizeof(unsigned int))); //RIGHT
				if (world.chunks[j].blocks[i].shouldRenderBack)
					glDrawRangeElements(GL_TRIANGLES, 12, 18, 6, GL_UNSIGNED_INT, (void*)(12*sizeof(unsigned int))); //BACK
				if (world.chunks[j].blocks[i].shouldRenderLeft)
					glDrawRangeElements(GL_TRIANGLES, 18, 24, 6, GL_UNSIGNED_INT, (void*)(18*sizeof(unsigned int))); //LEFT
				if (world.chunks[j].blocks[i].shouldRenderDown){
					glDrawRangeElements(GL_TRIANGLES, 24, 30, 6, GL_UNSIGNED_INT, (void*)(24*sizeof(unsigned int))); //BOTTOM
				}
				if (world.chunks[j].blocks[i].shouldRenderUp){
					glDrawRangeElements(GL_TRIANGLES, 30, 36, 6, GL_UNSIGNED_INT, (void*)(30*sizeof(unsigned int))); //TOP
				}
			}
			if (shouldGenerateChunk)
			{
				if (world.chunks[j].x == -((int)floor(camera.x / 32) + 1) &&
					world.chunks[j].z == -((int)floor(camera.z / 32) + 1)){
						shouldGenerateChunk = false;
				}
			}
		} 
		if (shouldGenerateChunk == true)
		{
			pthread_t th;
			info.generateX = -((int)floor(camera.x / 32) + 1) * 16;
			info.generateZ = -((int)floor(camera.z / 32) + 1) * 16;

			pthread_create(&th, NULL, &AddNewChunk, &info);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}