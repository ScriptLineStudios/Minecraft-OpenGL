#ifndef WORLD
#define WORLD

struct world{
    Chunk * chunks;
    int numberChunks;
};


typedef struct world World;

typedef struct {
	BaseInfo basicBlockData;
	World * world;
} Info;

World GenerateWorld(BaseInfo basicBlockData);
void * AddNewChunk(void * _info);

#endif