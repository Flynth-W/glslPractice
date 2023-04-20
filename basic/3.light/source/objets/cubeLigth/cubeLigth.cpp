#include "cubeLigth.hpp"
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void CubeLigth::addUniformShader(glm::mat4 *_projection, glm::mat4 *_view){
  projection=_projection;
  shader->setMat4("projection", *projection); 
  view=_view ;
}
void CubeLigth::addShader(const char *vertexShader, const char *fragShader){
  shader=new Shader();
  shader->load(vertexShader, fragShader );
}

void CubeLigth::addBuffer(float *vertices, unsigned int sizeVert, unsigned int *indices, unsigned int sizeInd){
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeVert, vertices, GL_STATIC_DRAW);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void CubeLigth::addTexture(const char *texture){};
void CubeLigth::Init(Camera *_camera){
      shader->use();
      camera=_camera;
};
void CubeLigth::Update(){};
void CubeLigth::Renderer(){
glm::vec3 lightPos(1.2f, 1.0f, -4.0f);
  shader->use();
  shader->setMat4("projection", *projection);
  shader->setMat4("view", *view);
  
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::mat4(1.0f);
  model = glm::translate(model, lightPos);
  model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
  shader->setMat4("model", model);

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);

};
