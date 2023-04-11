#pragma once


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera{
  private:
    unsigned int WIDTH;
    unsigned int HEIGHT;

    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
  public:
    glm::mat4 *projection;
    glm::mat4 *view;
    float cameraVelocity=2.5;

    Camera( unsigned int width , unsigned int height );
    ~Camera(){};

    void zoom(float fov);

    void left(float deltaTime);
    void right(float deltaTime);
    void up(float deltaTime);
    void down(float deltaTime);

    void angleChange(glm::vec3 front);
};
