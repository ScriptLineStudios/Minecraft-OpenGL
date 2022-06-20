#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>

GLfloat vertices[] =
{
        // front
    -0.5, -0.5,  0.5,   1.0f, 0.0f, 0.0f,
    0.5, -0.5,  0.5,    0.0f, 1.0f, 0.0f,
    0.5,  0.5,  0.5,    0.0f, 0.0f, 0.0f,
    -0.5,  0.5,  0.5,   1.0f, 0.0f, 0.0f,
// back
    -0.5, -0.5, -0.5,   1.0f, 0.0f, 1.0f,
    0.5, -0.5, -0.5,    0.0f, 1.0f, 0.0f,
    0.5,  0.5, -0.5,    0.0f, 1.0f, 1.0f,
    -0.5,  0.5, -0.5,   0.0f, 0.0f, 0.0f,
};

GLuint indices[] =
{
    0, 1, 2,
    2, 3, 0,
    1, 5, 6,
    6, 2, 1,
    7, 6, 5,
    5, 4, 7,
    4, 0, 3,
    3, 7, 4,
    4, 5, 1,
    1, 0, 4,
    3, 2, 6,
    6, 7, 3
};

struct block {
    GLuint VAO, VBO, EBO, shaderProgram;
    mat4 * model;
};
  
typedef struct block Block;

#define GLSL(src) "#version 330 core\n" #src

const char* vertexShaderSource = GLSL(
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;
    
    out vec3 color;


    uniform mat4 model;
    uniform mat4 view; 
    uniform mat4 proj; 
    void main()
    {
        color = aColor;
        gl_Position = proj * view * model * vec4(aPos, 0.5f);
    }
);

const char* fragmentShaderSource = GLSL(
    in vec3 color;
    out vec3 FragColor;
    void main()
    {
        FragColor = color;
    }
);


Block create_buffers(){
    Block block;

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();  
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

    GLuint VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    mat4 model;
    glm_mat4_identity(model);

    block.model = &model;
    block.VAO = VAO;
    block.VBO = VBO;
    block.EBO = EBO;
    block.shaderProgram = shaderProgram;
    return block;
}
