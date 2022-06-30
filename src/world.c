#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>
#include<stdlib.h>
#include<pthread.h>

#include "block.h"
#include "chunk.h"

struct world{
    Chunk * chunks;
    int numberChunks;
};

typedef struct world World;

World GenerateWorld(BaseInfo basicBlockData)
{
    World world;
    world.numberChunks = 9;

    world.chunks = malloc(sizeof(Chunk) * world.numberChunks);

    int i = 0;
	for (int x = 0; x < 3; x++){
		for (int z = 0; z < 3; z++){
			world.chunks[i] = generate_chunk(x*16, 0, z*16, basicBlockData);
			i++;
		}
	}

    return world;
}

typedef struct {
	BaseInfo basicBlockData;
	World * world;
} Info;

void * AddNewChunk(void * _info)
{
    Info * info = (Info *)_info;
    info->world->numberChunks++;
    info->world->chunks = realloc(info->world->chunks, info->world->numberChunks * sizeof(Chunk));
    info->world->chunks[info->world->numberChunks - 1] = generate_chunk(-16, 0, 0, info->basicBlockData);
    printf("Multi threaded chunk gen successful \n");
    pthread_exit(NULL);
}