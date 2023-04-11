#include "camera.hpp"

Camera::Camera(unsigned int width , unsigned int height) {
  projection= new glm::mat4(1.0f);
  view= new glm::mat4(1.0f);
  WIDTH  = width;
  HEIGHT = height ;
};

void Camera::zoom(float fov){ 
  *projection = glm::perspective(glm::radians(fov), (float)this->WIDTH / (float)this->HEIGHT , 0.1f, 100.0f);
};

void Camera::right(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::left(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::up(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos += cameraSpeed * cameraFront;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::down(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos -= cameraSpeed * cameraFront;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::angleChange(glm::vec3 front){
  cameraFront = glm::normalize(front);
};
