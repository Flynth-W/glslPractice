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
std::unordered_map<int,ButtonKey>mouseKeys;

void key_callback( GLFWwindow * window, int key, int scancode, int action, int mods){
  Event::HandleEvent(window, key,scancode,action,mods, &keys) ;
  return;
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
  Event::scroll_callback(window, xoffset,yoffset, &mouse);
}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
  Event::mouse_callback(window, xposIn, yposIn, &mouse);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
  Event::mouse_button_callback(window, button, action, mods, &mouseKeys);
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
  //add mouse buttons 
  mouseKeys[GLFW_MOUSE_BUTTON_RIGHT] = ButtonKey();
  mouseKeys[GLFW_MOUSE_BUTTON_LEFT] = ButtonKey();
  mouseKeys[GLFW_MOUSE_BUTTON_MIDDLE] = ButtonKey();
  mouseKeys[GLFW_MOUSE_BUTTON_4] = ButtonKey();
  mouseKeys[GLFW_MOUSE_BUTTON_5] = ButtonKey();
  mouse.x=500.0;
  mouse.y=500.0;

  color.red=0.0f;
  color.green=0.2f;
  color.blue=0.3f;
  color.alpha=1.0f;
  app.Init(1000,1000,"ProWin",color);
  app.setKeys(&keys);
  app.setMouse(&mouse);
  app.setMouseKeys(&mouseKeys);
  glfwSetKeyCallback (app.window, key_callback);
  glfwSetScrollCallback(app.window, scroll_callback);
  glfwSetCursorPosCallback(app.window, mouse_callback);
  glfwSetMouseButtonCallback(app.window,mouse_button_callback );
  glfwSetInputMode(app.window,GLFW_CURSOR,GLFW_CURSOR_DISABLED) ;
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


