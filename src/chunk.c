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
    Block blocks[4096];
    int numberBlocks;
    int x, z;
};

typedef struct chunk Chunk;

Block * GetBlockAt(Chunk * chunk, int x, int y, int z)
{
    int i;
    for (i = 0; i < 4096; i ++)
    {
        if (chunk->blocks[i].x == x && chunk->blocks[i].y == y && chunk->blocks[i].z == z)
        {
            return &chunk->blocks[i];
        }
    }
    
    return NULL;
}

Block * GetAllNeighbours(Chunk * chunk, Block * block)
{
    Block * neighbours = malloc(sizeof(Block) * 6);
    for (int i = 0; i < 4096; i++)
    {
        Block chunk_block = chunk->blocks[i];
        //left
        if (chunk_block.x == block->x - 2 
            && chunk_block.y == block->y 
                && chunk_block.z == block->z) neighbours[0] = chunk_block;
        //right
        if (chunk_block.x == block->x + 2 
            && chunk_block.y == block->y 
                && chunk_block.z == block->z) neighbours[1] = chunk_block;
        //up
        if (chunk_block.x == block->x 
            && chunk_block.y == block->y + 2
                && chunk_block.z == block->z) neighbours[2] = chunk_block;
        //down
        if (chunk_block.x == block->x 
            && chunk_block.y == block->y - 2
                && chunk_block.z == block->z) neighbours[3] = chunk_block;
        //front
        if (chunk_block.x == block->x 
            && chunk_block.y == block->y
                && chunk_block.z == block->z - 2) neighbours[4] = chunk_block;
        //back
        if (chunk_block.x == block->x 
            && chunk_block.y == block->y
                && chunk_block.z == block->z + 2) neighbours[5] = chunk_block;
    }
    return neighbours;
}

Chunk generate_chunk(int start_x, int start_y, int start_z, BaseInfo basic_block_data){
    Chunk chunk;
    int number_of_blocks = 0;
    int i = 0;
    for (int x = start_x; x < start_x+16; x++){
        for (int z = start_z; z < start_z+16; z++){
            int height = 14 + pnoise2d((double)x, (double)z, 0.11, 1, 1000000) * 3.0;
            if (height < 0) height = 1;
            for (int y = start_y; y < 16 ; y++){
                if (y < height) 
                {chunk.blocks[i] = create_buffers(basic_block_data, (x*2), (y*2), (z*2));
                 number_of_blocks++;}
                i++;
            }
        }
    }

   //printf("Number of blocks in chunk: %d \n", number_of_blocks);
    chunk.numberBlocks = number_of_blocks;

    for (int f = 0; f < 4096; f++){ 
        //If null, no neighbor!
        chunk.blocks[f].shouldRenderLeft = true;
        chunk.blocks[f].shouldRenderRight = true;
        chunk.blocks[f].shouldRenderUp = true;
        chunk.blocks[f].shouldRenderDown = true;
        chunk.blocks[f].shouldRenderBack = true;
        chunk.blocks[f].shouldRenderFront = true;

        //Block * neighbors = GetAllNeighbours(&chunk, &chunk.blocks[f]);

        Block * neighbour_left = GetBlockAt(&chunk, chunk.blocks[f].x - 2, 
                        chunk.blocks[f].y, chunk.blocks[f].z);

        Block * neighbour_right = GetBlockAt(&chunk, chunk.blocks[f].x + 2, 
                        chunk.blocks[f].y, chunk.blocks[f].z);

        Block * neighbour_up = GetBlockAt(&chunk, chunk.blocks[f].x, 
                        chunk.blocks[f].y + 2, chunk.blocks[f].z);
        
        Block * neighbour_down = GetBlockAt(&chunk, chunk.blocks[f].x, 
                        chunk.blocks[f].y - 2, chunk.blocks[f].z);

        Block * neighbour_front = GetBlockAt(&chunk, chunk.blocks[f].x, 
                        chunk.blocks[f].y, chunk.blocks[f].z - 2);
                    
        Block * neighbour_back = GetBlockAt(&chunk, chunk.blocks[f].x, 
                        chunk.blocks[f].y, chunk.blocks[f].z + 2);

        if (neighbour_up) chunk.blocks[f].shouldRenderUp = false;
        if (neighbour_down) chunk.blocks[f].shouldRenderDown = false;
        if (neighbour_front) chunk.blocks[f].shouldRenderFront = false;
        if (neighbour_back) chunk.blocks[f].shouldRenderBack = false;
        if (neighbour_right) chunk.blocks[f].shouldRenderRight = false;
        if (neighbour_left) chunk.blocks[f].shouldRenderLeft = false;
    }
    return chunk;
}