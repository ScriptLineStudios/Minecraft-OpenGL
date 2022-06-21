#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>
#include<string.h>
#include<stdlib.h>

#include "block.h"

struct chunk{
    Block blocks[4096];
    GLuint VAO;
};

typedef struct chunk Chunk;

Chunk generate_chunk(int start_x, int start_y, int start_z, BaseInfo basic_block_data){
    Chunk chunk;
	Block blocks[4096];
    int i = 0;
    for (int x = 0+start_x; x < 16+start_x; x++){
        for (int y = 0+start_y; y < 16+start_y; y++){
            for (int z = 0+start_z; z < 16+start_z; z++){
                    blocks[i] = create_buffers(basic_block_data, x*2, y*2, z*2);
                    i++;

            }
        }
    }
    for (int j = 0; j < i; j++){
        chunk.blocks[j] = blocks[j];
    }


    return chunk;
}