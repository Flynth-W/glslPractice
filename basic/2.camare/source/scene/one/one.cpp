#include "one.hpp"

void One::setKeys(std::unordered_map<int, ButtonKey> *_keys){
  keys=_keys;
}

One::One(){
  camera = new Camera(1000,1000);
}
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
  cube->addUniformShader(camera->projection, camera->view);
};
void One::Update(){
  auto buttonKey= keys->find(GLFW_KEY_W);
  if(buttonKey->second.getState() == ButtonState::Pressed){
    camera->up(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_S);
  if(buttonKey->second.getState() == ButtonState::Pressed){
    camera->down(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_A);
  if(buttonKey->second.getState() == ButtonState::Pressed){
    camera->left(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_D);
  if(buttonKey->second.getState() == ButtonState::Pressed){
    camera->right(0.003f); 
  }
};
void One::Render(){
//  obj1->Renderer();
  cube->Renderer();
};
void One::Release(){};

