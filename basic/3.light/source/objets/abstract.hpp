#pragma once

#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../utils/camera/camera.hpp"
#include <GL/glew.h>

unsigned int loadTexture(char const * path);

class Objet{
  public:
    virtual void addUniformShader(glm::mat4 *_projection,glm::mat4 * _view){};
    virtual void addShader(const char * vertexShader, const char * fragShader){};
    virtual void addBuffer(float * vertices , unsigned int sizeVert, unsigned int * indices , unsigned int  sizeInd){};
    virtual void addTexture(const char * texture){};
    virtual void Init(Camera *_camera){};
    virtual void Update(){};
    virtual void Renderer(){};
};
