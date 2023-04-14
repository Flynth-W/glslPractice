#include "app/app.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

App app;
colorWin color;
std::unordered_map<int,ButtonKey>keys;
Mouse mouse ;

void key_callback( GLFWwindow * window, int key, int scancode, int action, int mods){
  Event::HandleEvent(window, key,scancode,action,mods, &keys) ;
  return;
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
  Event::scroll_callback(window, xoffset,yoffset, &mouse);
}

int main()
{
  // ad keys
  keys[GLFW_KEY_P] =  ButtonKey();
  keys[GLFW_KEY_K] =  ButtonKey();
  
  keys[GLFW_KEY_W] =  ButtonKey();
  keys[GLFW_KEY_S] =  ButtonKey();
  keys[GLFW_KEY_A] =  ButtonKey();
  keys[GLFW_KEY_D] =  ButtonKey();
  
  
  color.red=0.0f;
  color.green=0.2f;
  color.blue=0.3f;
  color.alpha=1.0f;
  app.Init(1000,1000,"ProWin",color);
  app.setKeys(&keys);
  app.setMouse(&mouse);
  glfwSetKeyCallback (app.window, key_callback);
  glfwSetScrollCallback(app.window, scroll_callback);
    while ( app.isRun() )
    {
        Event::PreHandleEvent(&keys,&mouse);
        app.Events();
        app.Update();
        app.Render();
    }
    glfwTerminate();
    return 0;
}


