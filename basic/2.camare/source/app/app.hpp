#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../scene/one/one.hpp"
#include "../utils/camera/camera.hpp"
#include "../events/events.hpp"
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
    App();
    ~App(){};
    void Init(unsigned int height , unsigned int width,const char* title, colorWin __color);
    void setKeys(std::unordered_map<int,ButtonKey> *_keys);
    void Events();
    void Update();
    void Render();
    void Release();
    bool isRun();
    Mouse msd;
    GLFWwindow* window;
  private:
    colorWin _color;
    One sceneMain;
    Camera *camera ;
    std::unordered_map<int,ButtonKey>*keys;
};
