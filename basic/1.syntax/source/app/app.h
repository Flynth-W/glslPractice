#pragma once

#include "../scene/one/one.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;

struct colorWin{
  GLclampf red;
  GLclampf green;
  GLclampf blue;
  GLclampf alpha;
};

class App {
  public:
    App(){};
    ~App(){};
    void Init(unsigned int height , unsigned int width,const char* title, colorWin __color);
    void Event();
    void Update();
    void Render();
    void Release();
    bool isRun();
  private:
    GLFWwindow* window;
    colorWin _color;
    One sceneMain;
};
