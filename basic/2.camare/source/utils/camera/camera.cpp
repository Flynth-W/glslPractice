#include "camera.hpp"

Camera::Camera(unsigned int width , unsigned int height) {
  WIDTH  = width;
  HEIGHT = height ;
  projection= new glm::mat4(1.0f);
  ( *projection ) = glm::perspective(glm::radians(45.0f), (float)this->WIDTH / (float)this->HEIGHT , 0.1f, 100.0f);
  view= new glm::mat4(1.0f);
  ( *view  )= glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
};

void Camera::zooming(float sum){ 
  fov += sum;
  if (fov < 1.0f)
      fov = 1.0f;
  if (fov > 45.0f)
      fov = 45.0f;
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
