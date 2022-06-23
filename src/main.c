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

#define GLSL(src) "#version 330 core\n" #src

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



	BaseInfo basic_block_data = initialize_block_info();
	Chunk chunks[1];

	chunks[0] = generate_chunk(0, 0, 0, basic_block_data);  //Top Left



	  
	glfwSwapInterval(1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);



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
	camera.y = -32.0f;
	camera.z = -33.0f;
	camera.x = -32.0f;

	int z_offset = -32;



	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	while (!glfwWindowShouldClose(window))
	{
		//camera.rotation += 0.1;
		glClearColor(0.43f, 0.69f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

		//printf("%d \n", (int)camera.z);

		/*if ((int)camera.z % 16 == 0){
			chunks[2] = generate_chunk(0, 0, z_offset, basic_block_data);  //Top Left
			chunks[3] = generate_chunk(16, 0, z_offset, basic_block_data);  //Top Left
		}*/


        mat4 view;
        glm_mat4_identity(view);
        mat4 proj;
        glm_mat4_identity(proj);

    	glm_translate(view, (vec3){camera.x, camera.y, camera.z});
		//glm_rotate_at(view, (vec3){0.0f, 1.0f, 0.0f}, camera.rotation, (vec3){0.0f, 1.0f, 0.0f});
        glm_perspective(glm_rad(45), (float)(800/800), 0.1f, 100.0f, proj);

		handle_movement(&camera, window);

		for (int j = 0; j < 1; j++){
			for (int i = 0; i < 10; i++){
				glm_mat4_identity(chunks[j].blocks[i].model);

				glm_rotate(chunks[j].blocks[i].model, glm_rad(0), (vec3){0.0f, 1.0f, 0.0f});
				glm_translate(chunks[j].blocks[i].model, (vec3){chunks[j].blocks[i].x, chunks[j].blocks[i].y, chunks[j].blocks[i].z});

				glUseProgram(basic_block_data.shaderProgram);

				int modelLoc = glGetUniformLocation(basic_block_data.shaderProgram, "model");
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (const GLfloat *)chunks[j].blocks[i].model);
				int viewLoc = glGetUniformLocation(basic_block_data.shaderProgram, "view");
				glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (const GLfloat *)view);
				int projLoc = glGetUniformLocation(basic_block_data.shaderProgram, "proj");
				glUniformMatrix4fv(projLoc, 1, GL_FALSE, (const GLfloat *)proj);


				//chunks[0] = generate_chunk(0, 0, 0, basic_block_data);  //Top Left
				//chunks[1] = generate_chunk(16, 0, 0, basic_block_data);  //Top Left

				//chunks[2] = generate_chunk(0, 0, 16, basic_block_data);  //Top Left
				//chunks[3] = generate_chunk(16, 0, 16, basic_block_data);  //Top Left


				glBindTexture(GL_TEXTURE_2D, basic_block_data.texture);

				glBindVertexArray(basic_block_data.VAO);
				//glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

				/*glDrawRangeElements(GL_TRIANGLES, 0, 6, 6, GL_UNSIGNED_INT, (void*)(0*sizeof(unsigned int))); //FRONT 
				glDrawRangeElements(GL_TRIANGLES, 6, 12, 6, GL_UNSIGNED_INT, (void*)(6*sizeof(unsigned int))); //RIGHT
				glDrawRangeElements(GL_TRIANGLES, 12, 18, 6, GL_UNSIGNED_INT, (void*)(12*sizeof(unsigned int))); //BACK
				glDrawRangeElements(GL_TRIANGLES, 18, 24, 6, GL_UNSIGNED_INT, (void*)(18*sizeof(unsigned int))); //LEFT
				glDrawRangeElements(GL_TRIANGLES, 24, 30, 6, GL_UNSIGNED_INT, (void*)(24*sizeof(unsigned int))); //BOTTOM
				glDrawRangeElements(GL_TRIANGLES, 30, 36, 6, GL_UNSIGNED_INT, (void*)(30*sizeof(unsigned int))); //TOP*/

				if (chunks[j].blocks[i].shouldRenderFront){
					glDrawRangeElements(GL_TRIANGLES, 0, 6, 6, GL_UNSIGNED_INT, (void*)(0*sizeof(unsigned int))); //FRONT 
				}
				if (chunks[j].blocks[i].shouldRenderRight){
					glDrawRangeElements(GL_TRIANGLES, 6, 12, 6, GL_UNSIGNED_INT, (void*)(6*sizeof(unsigned int))); //RIGHT
				}
				if (chunks[j].blocks[i].shouldRenderBack){
					glDrawRangeElements(GL_TRIANGLES, 12, 18, 6, GL_UNSIGNED_INT, (void*)(12*sizeof(unsigned int))); //BACK
				}
				if (chunks[j].blocks[i].shouldRenderLeft){
					glDrawRangeElements(GL_TRIANGLES, 18, 24, 6, GL_UNSIGNED_INT, (void*)(18*sizeof(unsigned int))); //LEFT
				}
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