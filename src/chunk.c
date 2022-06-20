#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>
#include<string.h>

#include "block.h"

struct chunk{
    Block blocks[265];
};

typedef struct chunk Chunk;

Chunk generate_chunk(){
    Chunk chunk;
	Block blocks[256];
    int i;
    for (int x = 0; x < 16; x++){
        for (int y = 0; y < 16; y++){
            for (int z = 0; z < 2; z++){
                blocks[i] = create_buffers(x*2, y*2, z*2);
                i++;
            }
        }
    }
    for (int j = 0; j < 256; j++){
        chunk.blocks[j] = blocks[j];
        //printf("%d\n", chunk.blocks[j].x);
    }
    return chunk;

}