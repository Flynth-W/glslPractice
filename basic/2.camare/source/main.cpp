#include "app/app.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

App app;
colorWin color;
std::unordered_map<int,ButtonKey>keys;


void key_callback( GLFWwindow * window, int key, int scancode, int action, int mods){
  Event::HandleEvent(window, key,scancode,action,mods, &keys) ;
  
  //auto buttonKey = keys.find(key) ;
  //if (buttonKey == keys.cend()) {
  //    return;
  //}
  //if(buttonKey->second.getState() == ButtonState::None){
  //  std::cout << " none " << std::endl;
  //}
  //if(buttonKey->second.getState() == ButtonState::Pressed){
  //  std::cout << " press " << std::endl;
  //}
  //if(buttonKey->second.getState() == ButtonState::Repeat){
  //  std::cout << " Repeat" << std::endl;
  //}
  //if(buttonKey->second.getState() == ButtonState::Released){
  //  std::cout << " Released" << std::endl;
  //}
  return;
}


int main()
{
  // ad keys
  keys[GLFW_KEY_P] =  ButtonKey();
  keys[GLFW_KEY_K] =  ButtonKey();
  
  
  color.red=0.0f;
  color.green=0.2f;
  color.blue=0.3f;
  color.alpha=1.0f;
  app.Init(1000,1000,"ProWin",color);

  glfwSetKeyCallback (app.window, key_callback);
    while ( app.isRun() )
    {
        app.Events();
        app.Render();
    }
    glfwTerminate();
    return 0;
}


