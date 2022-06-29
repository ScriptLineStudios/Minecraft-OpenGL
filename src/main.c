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
	World world = GenerateWorld(basicBlockData);
	
	printf("%d \n", world.numberChunks);

	//printf("%d \n", world.numberChunks);

	/*Chunk * world.chunks = malloc(9 * sizeof(Chunk));

	int i = 0;
	for (int x = 0; x < 3; x++){
		for (int z = 0; z < 3; z++){
			world.chunks[i] = generate_chunk(x*16, 0, z*16, basicBlockData);
			i++;
		}
	}*/

	glfwSwapInterval(1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);


	Camera camera;

	int z_offset = -32;

	float rotation = 0;

	pthread_t th;


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	while (!glfwWindowShouldClose(window))
	{
		//camera.rotation += 0.1;
		glClearColor(0.43f, 0.69f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

		/*Chunk * chunk;
		pthread_create(&th, NULL, &GenerateNewChunk, &basicBlockData);
		pthread_join(th, (void **) &chunk);*/
    	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS){
			pthread_t th;
			Info info;
			info.basicBlockData = basicBlockData;
			info.world = &world;
			pthread_create(&th, NULL, &AddNewChunk, &info);
			//AddNewChunk(basicBlockData, &world, -16, 0);
        	
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
		} 

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}