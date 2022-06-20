#ifndef CHUNK
#define CHUNK

struct chunk{
    Block blocks[256];
};

typedef struct chunk Chunk;

Chunk generate_chunk();

#endif