#ifndef BLOCK
#define BLOCK

struct block {
    GLuint VAO, VBO, EBO, shaderProgram, texture, x, y, z;
    mat4 model;
};

typedef struct base_info{
    GLuint shaderProgram, VAO, VBO, EBO;
} BaseInfo;
 
typedef struct block Block;

Block create_buffers(BaseInfo basic_info, int _x, int _y, int _z);
BaseInfo initialize_block_info();

#endif