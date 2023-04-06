#include "app.h"

void App::Init(unsigned int height, unsigned int width, const char* title, colorWin __color){
  if(!glfwInit()){
    return;
  }
  window = glfwCreateWindow(height,width, title, NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    return ;
  }
  glfwMakeContextCurrent(window);
  GLenum err = glewInit();
  if(GLEW_OK != err)
  {
    cout << "error" << endl;
  }
  glEnable(GL_DEPTH_TEST);

  _color = __color ;
  sceneMain.Init();
}

void App::Event(){
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
