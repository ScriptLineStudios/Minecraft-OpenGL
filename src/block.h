#ifndef BLOCK
#define BLOCK

struct block {
    GLuint VAO, VBO, EBO, shaderProgram, texture, x, y, z;
    GLuint indices;
    mat4 model;
    GLuint offset1;
    GLuint offset2;
    GLuint offset3;
};

typedef struct base_info{
    GLuint shaderProgram, VAO, VBO, EBO, texture;
} BaseInfo;
 
typedef struct block Block;

Block create_buffers(BaseInfo basic_info, int _x, int _y, int _z);
BaseInfo initialize_block_info();

#endif