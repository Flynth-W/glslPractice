#include "one.hpp"


void One::Init(){
  //float vertices[] = {
  //    // positions          // colors           // texture coords
  //     0.5f,  0.5f, 0.0f,   0.0f, 0.4f, 0.4f,   1.0f, 1.0f, // top right
  //     0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
  //    -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
  //    -0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
  //};
  //unsigned int indices[] = {
  //    0, 1, 3, // first triangle
  //    1, 2, 3  // second triangle
  //};
  //
  //obj1 = new Square();
  //obj1->addShader("./shader/vertex.frag", "./shader/frag.frag");
  //obj1->addBuffer(vertices, sizeof(vertices), indices, sizeof(indices) ) ;
 
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.9f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 0.8f, 0.8f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 0.0f, 0.7f, 0.7f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 0.9f, 0.0f, 0.9f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, 0.4f, 0.4f, 0.4f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.9f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 0.8f, 0.8f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 0.0f, 0.7f, 0.7f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, 0.9f, 0.0f, 0.9f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 0.4f, 0.4f, 0.4f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.9f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 0.8f, 0.8f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.7f, 0.7f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.9f, 0.0f, 0.9f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 0.4f, 0.4f, 0.4f, 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,

         0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.9f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 0.8f, 0.8f, 0.0f, 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 0.0f, 0.7f, 0.7f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 0.9f, 0.0f, 0.9f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f, 0.4f, 0.4f, 0.4f, 0.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.9f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 0.8f, 0.8f, 0.0f, 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f, 0.0f, 0.7f, 0.7f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 0.9f, 0.0f, 0.9f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, 0.4f, 0.4f, 0.4f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.9f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 0.8f, 0.8f, 0.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, 0.0f, 0.7f, 0.7f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 0.9f, 0.0f, 0.9f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 0.4f, 0.4f, 0.4f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f
    };
  cube= new Cube(); 
  cube->addShader("./shader/cube/vertex.frag", "./shader/cube/frag.frag");
  cube->addBuffer(vertices, sizeof(vertices),0, 0);
  cube->addTexture("./1298130.jpg") ;
  cube->Init();
};
void One::Update(){

};
void One::Render(){
//  obj1->Renderer();
  cube->Renderer();
};
void One::Release(){};

