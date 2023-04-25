#include "boxTwoTexture.hpp"
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void BoxTwoTexture::addUniformShader(glm::mat4 *_projection, glm::mat4 *_view){
  projection=_projection;
  shader->setMat4("projection", *projection); 
  view=_view ;
}
void BoxTwoTexture::addShader(const char *vertexShader, const char *fragShader){
  shader=new Shader();
  shader->load(vertexShader, fragShader );
}

void BoxTwoTexture::addBuffer(float *vertices, unsigned int sizeVert, unsigned int *indices, unsigned int sizeInd){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeVert, vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}
void BoxTwoTexture::addTexture(const char *texture){
  texture1 = loadTexture("./img/cubeWooden.png");
  texture2 = loadTexture("./img/cubeGrenMetal.png");

};
void BoxTwoTexture::Init(Camera *_camera){
    shader->use();
    camera=_camera;
    shader->setInt("material.diffuse", 0);
    shader->setInt("material.specular", 1);
};
void BoxTwoTexture::Update(){};
void BoxTwoTexture::Renderer(){
glm::vec3 lightPos(1.2f, 1.0f, -4.0f);
  // be sure to activate shader when setting uniforms/drawing objects
  shader->use();
  shader->setVec3("light.position", lightPos);
  shader->setVec3("viewPos", camera->cameraPos);

  // light properties
  shader->setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
  shader->setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
  shader->setVec3("light.specular", 1.0f, 1.0f, 1.0f);

  // material properties
  shader->setFloat("material.shininess", 64.0f);

  // view/projection transformations
  shader->setMat4("projection", *projection);
  shader->setMat4("view", *view);

  // world transformation
  glm::mat4 model = glm::mat4(1.0f);
  shader->setMat4("model", model);

  //texture
  //// bind diffuse map
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture1);
  //// bind specular map
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, texture2);

  // render the cube
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);

};

