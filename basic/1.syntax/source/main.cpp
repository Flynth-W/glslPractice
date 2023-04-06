#include "app/app.h"
using namespace std;

int main() {
  App app;
  //colors
  colorWin color;
  color.red=0.0f;
  color.green=0.05;
  color.blue=0.1f;
  color.alpha=1;
  app.Init(1000,1000,"ProWin",color);


  
  while( app.isRun() ){
    app.Event();
    app.Update();
    app.Render();
  }
  app.Release();
}

