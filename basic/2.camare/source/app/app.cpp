#include "app.hpp"

void App::setKeys(std::unordered_map<int, ButtonKey> *_keys){
  keys=_keys;
  sceneMain.setKeys(_keys);
}
void App::setMouse(Mouse *_mouse){
  mouse =_mouse;
  sceneMain.setMouse(mouse);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
App::App(){
  camera= new Camera(1000,1000);
};
void App::Init(unsigned int height, unsigned int width, const char* title, colorWin __color){
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(height, width, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glViewport(0, 0, width, height);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
  GLenum err = glewInit();
  if(GLEW_OK != err)
  {
  }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);
  _color=__color;
  sceneMain.Init();
  //event
  //glfwSetKeyCallback (window, key_callback);
//  glfwSetKeyCallback (window, (event.lmb()  ));

}

void App::Events(){
  glfwPollEvents();   
}

void App::Update(){
  sceneMain.Update();
}

void App::Render(){
  glClearColor(_color.red,_color.green,_color.blue,_color.alpha);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

  sceneMain.Render();
  
  glfwSwapBuffers(window);
}

void App::Release(){
  sceneMain.Release();
  
  glfwDestroyWindow(window);
  glfwTerminate();

}
bool App::isRun(){
  return (!glfwWindowShouldClose(window) ) ;
}
