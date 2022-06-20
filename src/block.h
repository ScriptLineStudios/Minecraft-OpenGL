#ifndef BLOCK
#define BLOCK

struct block {
    GLuint VAO, VBO, EBO, shaderProgram;
    mat4 model;
};
  
typedef struct block Block;

Block create_buffers();

#endif