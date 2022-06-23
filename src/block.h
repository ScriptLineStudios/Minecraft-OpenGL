#ifndef BLOCK
#define BLOCK

struct block {
    GLuint VAO, VBO, EBO, shaderProgram, texture, x, y, z;
    GLuint indices;
    mat4 model;
    bool shouldRenderLeft;
    bool shouldRenderRight;
    bool shouldRenderFront;
    bool shouldRenderBack;
    bool shouldRenderUp;
    bool shouldRenderDown;
    int type;
    int position;
};

typedef struct base_info{
    GLuint shaderProgram, VAO, VBO, EBO, texture;
} BaseInfo;
 
typedef struct block Block;

Block create_buffers(BaseInfo basic_info, int _x, int _y, int _z);
BaseInfo initialize_block_info();

#endif