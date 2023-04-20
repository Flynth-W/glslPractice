#include "one.hpp"

void One::setKeys(std::unordered_map<int, ButtonKey> *_keys){
  keys=_keys;
}
void One::setMouse(Mouse *_mouse){
  mouse=_mouse;
}
void One::setMouseKeys(std::unordered_map<int, ButtonKey> *_mousekeys){
  mouseKeys=_mousekeys;
}
One::One(){
  camera = new Camera(1000,1000);
}
void One::Init(){
  
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
 
  cube= new CubeMaterial(); 
  cube->addShader("./shader/cubeMaterial/vs.frag", "./shader/cubeMaterial/fr.frag");
  cube->addBuffer(vertices, sizeof(vertices),0, 0);
  //cube->addTexture("./1298130.jpg") ;
  cube->Init(camera);
  cube->addUniformShader(camera->projection, camera->view);
  
  cubeligth= new CubeLigth(); 
  cubeligth->addShader("./shader/cubeLigth/vs.frag", "./shader/cubeLigth/fr.frag");
  cubeligth->addBuffer(vertices, sizeof(vertices),0, 0);
  cubeligth->Init(camera);
  cubeligth->addUniformShader(camera->projection, camera->view);
};
void One::Update(){
  auto buttonKey= keys->find(GLFW_KEY_W);
  if(buttonKey->second.getState() == ButtonState::Pressed || buttonKey->second.getState() == ButtonState::Repeat){
    camera->up(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_S);
  if(buttonKey->second.getState() == ButtonState::Pressed || buttonKey->second.getState() == ButtonState::Repeat){
    camera->down(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_A);
  if(buttonKey->second.getState() == ButtonState::Pressed || buttonKey->second.getState() == ButtonState::Repeat){
    camera->left(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_D);
  if(buttonKey->second.getState() == ButtonState::Pressed || buttonKey->second.getState() == ButtonState::Repeat){
    camera->right(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_K);
  if(buttonKey->second.getState() == ButtonState::Pressed || buttonKey->second.getState() == ButtonState::Repeat){
    camera->top(0.003f); 
  }
  buttonKey= keys->find(GLFW_KEY_J);
  if(buttonKey->second.getState() == ButtonState::Pressed || buttonKey->second.getState() == ButtonState::Repeat){
    camera->bottom(0.003f); 
  }
  if( mouse->whell == WhellState::Up ){
    camera->zooming(-1.0f);
  }
  if( mouse->whell == WhellState::Down ){
    camera->zooming(1.0f);
  }
  auto mouseKey= mouseKeys->find(GLFW_MOUSE_BUTTON_LEFT);
  if( mouseKey->second.getState() == ButtonState::Pressed ){
    camera->angleChange(mouse->x,mouse->y);
  }
};
void One::Render(){
//  obj1->Renderer();
  cube->Renderer();
  cubeligth->Renderer();
};
void One::Release(){};

