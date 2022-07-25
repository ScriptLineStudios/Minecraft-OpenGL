#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>
#include<stdbool.h>

struct camera {
    float x, y, z; 
    float rotation;
};

typedef struct camera Camera;

void handle_movement(Camera * camera, GLFWwindow* window){
    mat4 view;
    glm_mat4_identity(view);
    mat4 proj;
    glm_mat4_identity(proj);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        camera->z += 0.8f;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        camera->z -= 0.8f;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        camera->x += 0.8f;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        camera->x -= 0.8f;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS){
        camera->y += 0.5f;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        camera->y -= 0.5f;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        camera->rotation += 0.1f;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        camera->rotation -= 0.1f;
    }
}
