#ifndef CHUNK
#define CHUNK

struct chunk{
	Block blocks[10];
};

typedef struct chunk Chunk;

Chunk generate_chunk(int start_x, int start_y, int start_z, BaseInfo basic_block_data);

#endif