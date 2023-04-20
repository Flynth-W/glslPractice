#include "cubeMaterial.hpp"
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void CubeMaterial::addUniformShader(glm::mat4 *_projection, glm::mat4 *_view){
  projection=_projection;
  shader->setMat4("projection", *projection); 
  view=_view ;
}
void CubeMaterial::addShader(const char *vertexShader, const char *fragShader){
  shader=new Shader();
  shader->load(vertexShader, fragShader );
}

void CubeMaterial::addBuffer(float *vertices, unsigned int sizeVert, unsigned int *indices, unsigned int sizeInd){
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeVert, vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}
void CubeMaterial::addTexture(const char *texture){};
void CubeMaterial::Init(Camera *_camera){
      shader->use();
      camera=_camera;
};
void CubeMaterial::Update(){};
void CubeMaterial::Renderer(){
glm::vec3 lightPos(1.2f, 1.0f, -4.0f);
  shader->use();
  shader->setVec3("light.position", lightPos);
  shader->setVec3("viewPos", camera->cameraPos);

  // light properties
  glm::vec3 lightColor;
  lightColor.x = static_cast<float>(sin(glfwGetTime() * 2.0));
  lightColor.y = static_cast<float>(sin(glfwGetTime() * 0.7));
  lightColor.z = static_cast<float>(sin(glfwGetTime() * 1.3));
  glm::vec3 diffuseColor = lightColor   * glm::vec3(0.5f); // decrease the influence
  glm::vec3 ambientColor = diffuseColor * glm::vec3(0.9f); // low influence
  shader->setVec3("light.ambient", ambientColor);
  shader->setVec3("light.diffuse", diffuseColor);
  shader->setVec3("light.specular", 1.0f, 1.0f, 1.0f);

  // material properties
  shader->setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
  shader->setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
  shader->setVec3("material.specular", 0.5f, 0.5f, 0.5f); // specular lighting doesn't have full effect on this object's material
  shader->setFloat("material.shininess", 32.0f);

  // view/projection transformations
  shader->setMat4("projection", *projection);
  shader->setMat4("view", *view);

  // world transformation
  glm::mat4 model = glm::mat4(1.0f);
  shader->setMat4("model", model);

  // render the cube
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);

};
