#pragma once
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

class Shader{
  public:
    Shader(){};
    ~Shader(){};

    bool load(const std::string& vrxFl, const std::string& frgFl);
    void use();
  private:
    unsigned int ShdrPrgrm=glCreateProgram();

};
