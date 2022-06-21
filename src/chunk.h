#ifndef CHUNK
#define CHUNK

struct chunk{
    Block blocks[4096];
    GLuint VAO;
};

typedef struct chunk Chunk;

Chunk generate_chunk(int start_x, int start_y, int start_z, BaseInfo basic_block_data);

#endif