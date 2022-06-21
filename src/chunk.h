#ifndef CHUNK
#define CHUNK

struct chunk{
    Block blocks[4096];
};

typedef struct chunk Chunk;

Chunk generate_chunk(BaseInfo basic_block_data);

#endif