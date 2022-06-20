#ifndef BLOCK
#define BLOCK

struct block {
    GLuint VAO, VBO, EBO, shaderProgram, texture, x, y, z;
    mat4 model;
};
 
typedef struct block Block;

Block create_buffers(int _x, int _y, int _z);

#endif