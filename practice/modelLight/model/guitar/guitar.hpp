#pragma once
#include "../model.hpp"
#include "../../utils/camera/camera.hpp"

class Guitar{
  private:
    Shader * shader;
    Model  * model;
    Camera * camera;
  public:
    void Init(Camera *_camera);
    void Update();
    void Render();
};

