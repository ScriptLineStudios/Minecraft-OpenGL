#ifndef WORLD
#define WORLD

struct world{
    Chunk * chunks;
    int numberChunks;
};

typedef struct world World;

World GenerateWorld(BaseInfo basicBlockData);
void AddNewChunk(BaseInfo basicBlockData, World * world, int x, int z);

#endif