#pragma once

class Objet{
  public:
    virtual void addShader(const char * vertexShader, const char * fragShader){};
    virtual void addBuffer(float * vertices , unsigned int sizeVert, unsigned int * indices , unsigned int  sizeInd){};
    virtual void Init(){};
    virtual void Update(){};
    virtual void Renderer(){};
};
