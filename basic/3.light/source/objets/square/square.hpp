#pragma once

#include "../abstract.hpp"
// shader class
#include "./../Shader/Shader.h"


class Square: public Objet{

  public:
    void addShader(const char * vertexShader, const char * fragShader) override ;
    void addBuffer(float * vertices , unsigned int sizeVert, unsigned int * indices , unsigned int  sizeInd) override ;
    void Init(Camera *_camera)      override ;
    void Update()    override ;
    void Renderer()  override ;
  private:
    Shader * shader;
    unsigned int VBO, VAO, EBO;
};
