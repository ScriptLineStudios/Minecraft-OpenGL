#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>
#include<stdlib.h>

#include "block.h"
#include "camera.h"
#include "chunk.h"
#include "perlin.h"

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
	static Chunk chunks[24];

	chunks[0] = generate_chunk(0, 0, 0, basicBlockData);  //Top Left
	chunks[1] = generate_chunk(16, 0, 0, basicBlockData);  //Top Left
	chunks[2] = generate_chunk(32, 0, 0, basicBlockData);  //Top Left
	chunks[3] = generate_chunk(48, 0, 0, basicBlockData);  //Top Left

	chunks[4] = generate_chunk(0, 0, 16, basicBlockData);  //Top Left
	chunks[5] = generate_chunk(16, 0, 16, basicBlockData);  //Top Left
	chunks[6] = generate_chunk(32, 0, 16, basicBlockData);  //Top Left
	chunks[7] = generate_chunk(48, 0, 16, basicBlockData);  //Top Left

	chunks[8] = generate_chunk(0, 0, 32, basicBlockData);  //Top Left
	chunks[9] = generate_chunk(16, 0, 32, basicBlockData);  //Top Left
	chunks[10] = generate_chunk(32, 0, 32, basicBlockData);  //Top Left
	chunks[11] = generate_chunk(48, 0, 32, basicBlockData);  //Top Left



	chunks[12] = generate_chunk(0, 0, 48, basicBlockData);  //Top Left
	chunks[13] = generate_chunk(16, 0, 48, basicBlockData);  //Top Left
	chunks[14] = generate_chunk(32, 0, 48, basicBlockData);  //Top Left
	chunks[15] = generate_chunk(48, 0, 48, basicBlockData);  //Top Left

	chunks[16] = generate_chunk(0, 0, 64, basicBlockData);  //Top Left
	chunks[17] = generate_chunk(16, 0, 64, basicBlockData);  //Top Left
	chunks[18] = generate_chunk(32, 0, 64, basicBlockData);  //Top Left
	chunks[19] = generate_chunk(48, 0, 64, basicBlockData);  //Top Left

	chunks[20] = generate_chunk(0, 0, 80, basicBlockData);  //Top Left
	chunks[21] = generate_chunk(16, 0, 80, basicBlockData);  //Top Left
	chunks[22] = generate_chunk(32, 0, 80, basicBlockData);  //Top Left
	chunks[23] = generate_chunk(48, 0, 80, basicBlockData);  //Top Left


	glfwSwapInterval(1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);



	Camera camera;
	camera.y = -32.0f;
	camera.z = -33.0f;
	camera.x = -32.0f;

	int z_offset = -32;

	float rotation = 0;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	while (!glfwWindowShouldClose(window))
	{
		//camera.rotation += 0.1;
		glClearColor(0.43f, 0.69f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

		//printf("%d \n", (int)camera.z);

		/*if ((int)camera.z % 16 == 0){
			chunks[2] = generate_chunk(0, 0, z_offset, basicBlockData);  //Top Left
			chunks[3] = generate_chunk(16, 0, z_offset, basicBlockData);  //Top Left
		}*/


        mat4 view;
        glm_mat4_identity(view);
        mat4 proj;
        glm_mat4_identity(proj);

    	glm_translate(view, (vec3){camera.x, camera.y, camera.z});
		//glm_rotate_at(view, (vec3){0.0f, 1.0f, 0.0f}, camera.rotation, (vec3){0.0f, 1.0f, 0.0f});
        glm_perspective(glm_rad(45), (float)(800/800), 0.1f, 1000.0f, proj);

		handle_movement(&camera, window);

		glUseProgram(basicBlockData.shaderProgram);
		glBindTexture(GL_TEXTURE_2D, basicBlockData.texture);

		glBindVertexArray(basicBlockData.VAO);

		int viewLoc = glGetUniformLocation(basicBlockData.shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (const GLfloat *)view);
		int projLoc = glGetUniformLocation(basicBlockData.shaderProgram, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, (const GLfloat *)proj);

		for (int j = 0; j < 24; j++){
			for (int i = 0; i < 4096; i++){
				glm_mat4_identity(chunks[j].blocks[i].model);

				//glm_rotate(chunks[j].blocks[i].model, glm_rad(camera.rotation), (vec3){0.0f, 1.0f, 0.0f});
				glm_translate(chunks[j].blocks[i].model, (vec3){chunks[j].blocks[i].x, chunks[j].blocks[i].y, chunks[j].blocks[i].z});

				int modelLoc = glGetUniformLocation(basicBlockData.shaderProgram, "model");
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (const GLfloat *)chunks[j].blocks[i].model);
				
				if (chunks[j].blocks[i].shouldRenderFront)
					glDrawRangeElements(GL_TRIANGLES, 0, 6, 6, GL_UNSIGNED_INT, (void*)(0*sizeof(unsigned int))); //FRONT 
				if (chunks[j].blocks[i].shouldRenderRight)
					glDrawRangeElements(GL_TRIANGLES, 6, 12, 6, GL_UNSIGNED_INT, (void*)(6*sizeof(unsigned int))); //RIGHT
				if (chunks[j].blocks[i].shouldRenderBack)
					glDrawRangeElements(GL_TRIANGLES, 12, 18, 6, GL_UNSIGNED_INT, (void*)(12*sizeof(unsigned int))); //BACK
				if (chunks[j].blocks[i].shouldRenderLeft)
					glDrawRangeElements(GL_TRIANGLES, 18, 24, 6, GL_UNSIGNED_INT, (void*)(18*sizeof(unsigned int))); //LEFT
				if (chunks[j].blocks[i].shouldRenderDown){
					glDrawRangeElements(GL_TRIANGLES, 24, 30, 6, GL_UNSIGNED_INT, (void*)(24*sizeof(unsigned int))); //BOTTOM
				}
				if (chunks[j].blocks[i].shouldRenderUp){
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