#pragma once

#include "../abstract.hpp"
#include "./../Shader/ShaderObj.hpp"



class Cube: public Objet{

  public:
    void addUniformShader(glm::mat4 *_projection,glm::mat4 * _view) override;
    void addShader(const char * vertexShader, const char * fragShader) override ;
    void addBuffer(float * vertices , unsigned int sizeVert, unsigned int * indices , unsigned int  sizeInd) override ;
    void addTexture(const char * texture) override;
    void Init(Camera *_camera)      override ;
    void Update()    override ;
    void Renderer()  override ;
  private:
    ShaderObj * shader;
    unsigned int VBO, VAO;
    unsigned int texture1, texture2;
    glm::mat4 *projection;
    glm::mat4 *view;
    Camera *camera;
};
