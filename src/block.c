#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stb/stb.h>
#include<time.h>

GLfloat vertices[192] = {
   -0.5, -0.5,  -0.5,   0.5f, 0.0f, 0.0f,    0.0f, 0.0f, // bottom left back (0)
    0.5, -0.5,  -0.5,   0.0f, 0.5f, 0.0f,    0.0f, 0.49f, // bottom right back(1)
    0.5,  0.5,  -0.5,   0.0f, 0.0f, 0.0f,    0.49f, 0.49f, // top right back(2)
   -0.5,  0.5,  -0.5,   0.5f, 0.0f, 0.0f,    0.49f, 0.0f, //top left back(3)

    -0.5, -0.5,  0.5,   0.5f, 0.0f, 0.0f,    0.0f, 0.0f, // bottom left front(4)
    0.5, -0.5,  0.5,   0.0f, 0.5f, 0.0f,    0.0f, 0.49f, // bottom right front(5)
    0.5,  0.5,  0.5,   0.0f, 0.0f, 0.0f,    0.49f, 0.49f, // top right front(6)
   -0.5,  0.5,  0.5,   0.5f, 0.0f, 0.0f,    0.49f, 0.0f, //top left front(7)

   -0.5,  0.5, -0.5,   0.5f, 0.0f, 0.0f,    0.0f, 0.49f, // top left back(8)
    0.5,  0.5, -0.5,   0.0f, 0.0f, 0.0f,    0.49f, 0.49f, // top right back(9)

    0.5,  0.5,  0.5,   0.0f, 0.0f, 0.0f,    0.0f, 1.0f, // top right front (10)
   -0.5,  0.5,  0.5,   0.5f, 0.0f, 0.0f,    0.49f, 1.0f, //top left front(11)

   -0.5, -0.5,  -0.5,   0.5f, 0.0f, 0.0f,    0.0f, 0.0f, // bottom left back(12)
    0.5, -0.5,  -0.5,   0.0f, 0.5f, 0.0f,    0.0f, 0.49f, // bottom right back(13)
    0.5, -0.5,  0.5,   0.0f, 0.5f, 0.0f,    0.49f, 0.49f, // bottom right front (14)
   -0.5, -0.5,  0.5,   0.5f, 0.0f, 0.0f,    0.49f, 0.0f, //bottom left front(15)

   -0.5,  0.5, -0.5,   0.5f, 0.0f, 0.0f,     0.49f, 0.0f, // top left back(16)
   -0.5,  0.5,  0.5,   0.5f, 0.0f, 0.0f,     0.49f, 0.49f, // top left front(17)
   -0.5, -0.5,  0.5,   0.5f, 0.0f, 0.0f,     0.0f, 0.49f, // bottom left front(18)
   -0.5, -0.5,  -0.5,  0.5f, 0.0f, 0.0f,     0.0f, 0.0f, // bottom left back (19)

    0.5,  0.5, -0.5,   0.0f, 0.0f, 0.0f,    0.49f, 0.0f, // top right back(20)
    0.5,  0.5,  0.5,   0.0f, 0.0f, 0.0f,    0.49f, 0.49f, // top right front(21)
    0.5, -0.5,  0.5,   0.0f, 0.5f, 0.0f,    0.0f, 0.49f, // bottom right front(22)
    0.5, -0.5,  -0.5,   0.0f, 0.5f, 0.0f,    0.0f, 0.0f, // bottom right back(23)
};

GLuint indices[] =
{
    0, 1, 2,
    2, 3, 0,
    
    20, 21, 22,
    22, 23, 20,

    7, 6, 5,
    5, 4, 7,
    //left
    16, 17, 18,
    18, 19, 16,

    12, 13, 14,
    14, 15, 12,

    8, 9, 10,
    10, 11, 8
};

struct block {
    GLuint VAO, VBO, EBO, shaderProgram, texture;
    GLint x, y, z;
    GLuint * indices;
    mat4 * model;
    bool shouldRenderLeft;
    bool shouldRenderRight;
    bool shouldRenderFront;
    bool shouldRenderBack;
    bool shouldRenderUp;
    bool shouldRenderDown;
    int type;
    int position;
};
  
typedef struct block Block;

#define GLSL(src) "#version 330 core\n" #src

const char* vertexShaderSource = GLSL(
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;
    layout (location = 2) in vec2 aTex;

    out vec3 color;

    out vec2 texCoord;

    uniform mat4 model;
    uniform mat4 view; 
    uniform mat4 proj; 
    void main()
    {
        color = aColor;
        gl_Position = proj * view * model * vec4(aPos, 0.5f);
        texCoord = aTex;
    }
);

const char* fragmentShaderSource = GLSL(
    in vec3 color;
    out vec3 FragColor;
    in vec2 texCoord;

    uniform sampler2D tex0;
    void main()
    {
        FragColor = texture(tex0, texCoord).rgb;
    }
);

typedef struct base_info{
    GLuint shaderProgram, VAO, VBO, EBO, texture, texture_2;
} BaseInfo;

BaseInfo initialize_block_info(){
    BaseInfo basic_info;

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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    int imgWidth, imgHeight, colors;
    unsigned char* bytes = stbi_load("assets/textures.png", &imgWidth, &imgHeight, &colors, 0);

    if (!bytes){
        printf("Unable to load image for the following reason: %s \n", stbi_failure_reason());
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint tex0Uni = glGetUniformLocation(shaderProgram, "tex0");
    glUseProgram(shaderProgram);
    glUniform1i(tex0Uni, 0);

    basic_info.shaderProgram = shaderProgram;
    basic_info.VAO = VAO;
    basic_info.VBO = VBO;
    basic_info.EBO = EBO;
    basic_info.texture = texture;
    
    return basic_info;
}


Block create_buffers(BaseInfo basic_info, int _x, int _y, int _z){
    Block block;

    mat4 model;
    glm_mat4_identity(model);

    block.model = &model;
    block.texture = basic_info.texture;

    block.x = (GLint) _x;
    block.y = (GLint) _y;
    block.z = (GLint) _z;

    block.indices = indices;
    return block;
}
