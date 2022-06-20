#ifndef BLOCK
#define BLOCK

struct block {
    GLuint VAO, VBO, EBO, shaderProgram, texture;
    mat4 model;
};

  
typedef struct block Block;

Block create_buffers();

#endif