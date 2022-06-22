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
        // Get the blocks x: subtract one for block on the left add one for block on the left
        // Get the blocks y: subtract one for block on the top add one for block on the bottom
        // Get the blocks z: subtract one for block in front add one for block in the back
    }

    for (int f = 0; f < i; f++){ 
        GLuint neighbor_x = chunk.blocks[f].x - 2;
        GLuint neighbor_y = chunk.blocks[f].y + 2;
        GLuint neighbor_z = chunk.blocks[f].z - 2;

        //Before running, assume all faces must be drawn
        chunk.blocks[f].shouldRenderLeft = true;
        chunk.blocks[f].shouldRenderRight = true;
        chunk.blocks[f].shouldRenderUp = true;
        chunk.blocks[f].shouldRenderDown = true;
        chunk.blocks[f].shouldRenderBack = true;
        chunk.blocks[f].shouldRenderFront = true;

        for (int c = 0; c < i; c++){
            if (chunk.blocks[c].x == neighbor_x){ //If the neighbouting x block exists (dont render the face!)
                chunk.blocks[f].shouldRenderLeft = false;
            }   
            if (chunk.blocks[c].y == neighbor_y){ //If the neighbouting y block exists (dont render the face!)
                chunk.blocks[f].shouldRenderUp = false;
            }  
            if (chunk.blocks[c].z == neighbor_z){ //If the neighbouting z block exists (dont render the face!)
                chunk.blocks[f].shouldRenderFront = false;
            }  
        }

        GLuint _neighbor_x = chunk.blocks[f].x + 2;
        GLuint _neighbor_y = chunk.blocks[f].y - 2;
        GLuint _neighbor_z = chunk.blocks[f].z + 2;

        for (int c = 0; c < i; c++){
            if (chunk.blocks[c].x == _neighbor_x){ //If the neighbouting x block exists (dont render the face!)
                chunk.blocks[f].shouldRenderRight = false;
            }   
            if (chunk.blocks[c].y == _neighbor_y){ //If the neighbouting y block exists (dont render the face!)
                chunk.blocks[f].shouldRenderDown = false;
            }  
            if (chunk.blocks[c].z == _neighbor_z){ //If the neighbouting z block exists (dont render the face!)
                chunk.blocks[f].shouldRenderBack = false;
            }  
        }
    }

    return chunk;
}