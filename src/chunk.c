
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
#include "perlin.h"

struct chunk{
    Block blocks[10];

};

typedef struct chunk Chunk;

Chunk generate_chunk(int start_x, int start_y, int start_z, BaseInfo basic_block_data){
    Chunk chunk;
    chunk.blocks[0] = create_buffers(basic_block_data, 2, 2, 2);
    chunk.blocks[0].type = 1;
    chunk.blocks[1] = create_buffers(basic_block_data, 4, 2, 2);
    chunk.blocks[1].type = 1;
    chunk.blocks[2] = create_buffers(basic_block_data, 6, 2, 2);
    chunk.blocks[2].type = 1;
    
    chunk.blocks[3] = create_buffers(basic_block_data, 8, 2, 2);
    chunk.blocks[3].type = 1;
    
    chunk.blocks[4] = create_buffers(basic_block_data, 10, 2, 2);
    chunk.blocks[4].type = 1;
    
    chunk.blocks[5] = create_buffers(basic_block_data, 12, 2, 2);
    chunk.blocks[5].type = 1;
    
    chunk.blocks[6] = create_buffers(basic_block_data, 14, 2, 2);
    chunk.blocks[6].type = 0;
    
    chunk.blocks[7] = create_buffers(basic_block_data, 16, 2, 2);
    chunk.blocks[7].type = 1;

    chunk.blocks[8] = create_buffers(basic_block_data, 18, 2, 2);
    chunk.blocks[8].type = 1;

    chunk.blocks[9] = create_buffers(basic_block_data, 20, 2, 2);
    chunk.blocks[9].type = 1;

    int i = 10;
    for (int f = 0; f < i; f++){ 
        if (chunk.blocks[f].type != 0){
            chunk.blocks[f].shouldRenderLeft = true;
            chunk.blocks[f].shouldRenderRight = true;
            chunk.blocks[f].shouldRenderUp = true;
            chunk.blocks[f].shouldRenderDown = true;
            chunk.blocks[f].shouldRenderBack = true;
            chunk.blocks[f].shouldRenderFront = true;
        

            for (int c = 0; c < i; c++){
                if (chunk.blocks[c].x == chunk.blocks[f].x - 2) chunk.blocks[f].shouldRenderLeft = false;
                if (chunk.blocks[c].y == chunk.blocks[f].y + 2) chunk.blocks[f].shouldRenderUp = false;
                if (chunk.blocks[c].z == chunk.blocks[f].z - 2) chunk.blocks[f].shouldRenderFront = false;

                if (chunk.blocks[c].x == chunk.blocks[f].x + 2) chunk.blocks[f].shouldRenderRight = false;
                if (chunk.blocks[c].y == chunk.blocks[f].y - 2) chunk.blocks[f].shouldRenderDown = false;
                if (chunk.blocks[c].z == chunk.blocks[f].z + 2) chunk.blocks[f].shouldRenderBack = false;
            }

        }
        else{
            chunk.blocks[f].shouldRenderLeft = false;
            chunk.blocks[f].shouldRenderRight = false;
            chunk.blocks[f].shouldRenderUp = false;
            chunk.blocks[f].shouldRenderDown = false;
            chunk.blocks[f].shouldRenderBack = false;
            chunk.blocks[f].shouldRenderFront = false;

            for (int c = 0; c < i; c++){
                if (chunk.blocks[c].x == chunk.blocks[f].x - 2) chunk.blocks[f].shouldRenderLeft = true;
                if (chunk.blocks[c].y == chunk.blocks[f].y + 2) chunk.blocks[f].shouldRenderUp = true;
                if (chunk.blocks[c].z == chunk.blocks[f].z - 2) chunk.blocks[f].shouldRenderFront = true;

                if (chunk.blocks[c].x == chunk.blocks[f].x + 2) chunk.blocks[f].shouldRenderRight = true;
                if (chunk.blocks[c].y == chunk.blocks[f].y - 2) chunk.blocks[f].shouldRenderDown = true;
                if (chunk.blocks[c].z == chunk.blocks[f].z + 2) chunk.blocks[f].shouldRenderBack = true;
            }
        }
    }

    return chunk;
}