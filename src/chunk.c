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
};

typedef struct chunk Chunk;

Chunk generate_chunk(BaseInfo basic_block_data){
    Chunk chunk;
	Block blocks[4096];
    int i = 0;
    for (int x = 0; x < 16; x++){
        for (int y = 0; y < 16; y++){
            for (int z = 0; z < 16; z++){
                blocks[i] = create_buffers(basic_block_data, x*2, y*2, z*2);
                i++;
            }
        }
    }
    printf("%d \n", i);
    for (int j = 0; j < i; j++){
        chunk.blocks[j] = blocks[j];
        //printf("(%d %d %d) (%d %d %d) \n", chunk.blocks[j].x, chunk.blocks[j].y, chunk.blocks[j].z,
          //      blocks[j].x, blocks[j].y, blocks[j].z);
    }
    return chunk;

}