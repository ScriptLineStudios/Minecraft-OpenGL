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
    int generateX, generateZ;
} Info;

World GenerateWorld(BaseInfo basicBlockData);
void * AddNewChunk(void * _info);
void * RemoveChunk(void * _info);

#endif