#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

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
            world.chunks[i].x = x;
            world.chunks[i].z = z;
			i++;
		}
	}

    return world;
}

typedef struct {
	BaseInfo basicBlockData;
	World * world;
    int generateX, generateZ;
} Info;

void * RemoveChunk(void * _info)
{
    Info * info = (Info *)_info;
    info->world->numberChunks--;
    pthread_exit(NULL);
}

void * AddNewChunk(void * _info)
{
    Info * info = (Info *)_info;
    info->world->numberChunks++;
    info->world->chunks = realloc(info->world->chunks, info->world->numberChunks * sizeof(Chunk));
    info->world->chunks[info->world->numberChunks - 1] = generate_chunk(info->generateX, 0, info->generateZ, info->basicBlockData);
    info->world->chunks[info->world->numberChunks - 1].x = info->generateX / 16;
    info->world->chunks[info->world->numberChunks - 1].z = info->generateZ / 16;
    pthread_exit(NULL);
}