#include "guitar.hpp"
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void Guitar::Init(Camera *_camera){
  shader = new Shader("./shader/model/vs.frag","./shader/model/fs.frag");
  model  = new Model("./backpack/backpack.obj");
  camera = _camera;
}
void Guitar::Update(){};
void Guitar::Render(){
  shader->use(); 
  glm::mat4 modelG = glm::mat4(1.0f);
  modelG = glm::rotate(modelG, glm::radians(0.0f), glm::vec3(1.0f, 0.3f, 0.5f));
  shader->setMat4("model", modelG);
  shader->setMat4("projection", *( (*camera).projection ) ); 
  shader->setMat4("view", *( (*camera).view ));
  //materal
  shader->setInt("material.diffuse", 0);
  shader->setInt("material.specular", 2);
  shader->setFloat("material.shininess", 32.0f);
  //light global (sun)
  shader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
  shader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
  shader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
  shader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

  // point light 1
  shader->setVec3("pointLight.position", 1.2f, 1.0f, 2.0f);
  shader->setVec3("pointLight.ambient", 0.05f, 0.05f, 0.05f);
  shader->setVec3("pointLight.diffuse", 0.8f, 0.8f, 0.8f);
  shader->setVec3("pointLight.specular", 1.0f, 1.0f, 1.0f);
  shader->setFloat("pointLight.constant", 1.0f);
  shader->setFloat("pointLight.linear", 0.09f);
  shader->setFloat("pointLight.quadratic", 0.032f);
  // spotLight
  shader->setVec3("spotLight.position", camera->cameraPos);
  shader->setVec3("spotLight.direction", camera->cameraFront);
  shader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
  shader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
  shader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
  shader->setFloat("spotLight.constant", 1.0f);
  shader->setFloat("spotLight.linear", 0.09f);
  shader->setFloat("spotLight.quadratic", 0.032f);
  shader->setFloat("spotLight.cutOff", glm::cos(glm::radians(5.5f)));
  shader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(9.5f)));     
  model->Draw(*shader);
}
