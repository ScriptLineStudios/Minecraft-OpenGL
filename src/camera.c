#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cglm/cglm.h>
#include<cglm/mat4.h>
#include<cglm/vec3.h>
#include<cglm/clipspace/persp.h>

struct camera {
    float x, y, z; //hmm yes
};

typedef struct camera Camera;

void handle_movement(Camera * camera, GLFWwindow* window){

    mat4 view;
    glm_mat4_identity(view);
    mat4 proj;
    glm_mat4_identity(proj);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        camera->z += 0.3f;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        camera->z -= 0.3f;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        camera->x += 0.3f;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        camera->x -= 0.3f;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS){
        camera->y += 0.1f;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        camera->y -= 0.1f;
    }
}
