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

	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	/*Block blocks[256];
	for (int i = 0; i < 256; i++){
		chunk.blocks[i] = create_buffers(i, 0, 0);
	}*/

	BaseInfo basic_block_data = initialize_block_info();
	Chunk chunk = generate_chunk(basic_block_data);
	
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
		//rotation += 0.1;
		glClearColor(0.43f, 0.69f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

        mat4 view;
        glm_mat4_identity(view);
        mat4 proj;
        glm_mat4_identity(proj);

    	glm_translate(view, (vec3){camera.x, camera.y, camera.z});
        glm_perspective(glm_rad(45.0f), (float)(800/800), 0.1f, 100.0f, proj);

		handle_movement(&camera, window);

		for (int i = 0; i < 256; i++){
			glm_mat4_identity(chunk.blocks[i].model);

			glm_rotate(chunk.blocks[i].model, glm_rad(0), (vec3){0.0f, 1.0f, 0.0f});
			glm_translate(chunk.blocks[i].model, (vec3){chunk.blocks[i].x, chunk.blocks[i].y, chunk.blocks[i].z});

			glUseProgram(basic_block_data.shaderProgram);

			int modelLoc = glGetUniformLocation(basic_block_data.shaderProgram, "model");
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (const GLfloat *)chunk.blocks[i].model);
			int viewLoc = glGetUniformLocation(basic_block_data.shaderProgram, "view");
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (const GLfloat *)view);
			int projLoc = glGetUniformLocation(basic_block_data.shaderProgram, "proj");
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, (const GLfloat *)proj);

		    glBindTexture(GL_TEXTURE_2D, chunk.blocks[i].texture);
			
			glBindVertexArray(basic_block_data.VAO);
			glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		}



		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}