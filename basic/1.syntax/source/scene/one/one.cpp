#include "one.h"


void One::Init(){
  float vertices[] = {
      // positions          // colors           // texture coords
       0.5f,  0.5f, 0.0f,   0.0f, 0.4f, 0.4f,   1.0f, 1.0f, // top right
       0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
      -0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
  };
  unsigned int indices[] = {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };
  
  obj1 = new Square();
  obj1->addShader("./shader/vertex.frag", "./shader/frag.frag");
  obj1->addBuffer(vertices, sizeof(vertices), indices, sizeof(indices) ) ;

};
void One::Update(){

};
void One::Render(){
  obj1->Renderer();
};
void One::Release(){};

