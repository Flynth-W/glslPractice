#include "cube1.hpp"
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void Cube1::addUniformShader(glm::mat4 *_projection, glm::mat4 *_view){
  projection=_projection;
  shader->setMat4("projection", *projection); 
  view=_view ;
}
void Cube1::addShader(const char *vertexShader, const char *fragShader){
  shader=new Shader();
  shader->load(vertexShader, fragShader );
}

void Cube1::addBuffer(float *vertices, unsigned int sizeVert, unsigned int *indices, unsigned int sizeInd){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeVert, vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}
void Cube1::addTexture(const char *texture){};
void Cube1::Init(Camera *_camera){
      shader->use();
      camera=_camera;
};
void Cube1::Update(){};
void Cube1::Renderer(){
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
  shader->use();
  shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
  shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);
  shader->setVec3("lightPos", lightPos);
  shader->setVec3("viewPos", camera->cameraPos);

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
