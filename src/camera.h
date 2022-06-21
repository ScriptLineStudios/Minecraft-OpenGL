#ifndef CAMERA
#define CAMERA

struct camera {
    float x, y, z; 
    float rotation;
};

typedef struct camera Camera;

void handle_movement(Camera * camera, GLFWwindow * window);

#endif