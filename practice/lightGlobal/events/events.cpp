#include "events.hpp"
// class ButtonKey

ButtonKey::ButtonKey(){
  state= new ButtonState(ButtonState::None);
}
void ButtonKey::setState(ButtonState _state ){  
  *state=_state; 
} 
ButtonState ButtonKey::getState(){ 
  return *state;
}
void ButtonKey::Release(){ 
  *state=ButtonState::None ;
}
// class Event
//Event::Event(std::unordered_map<int,ButtonKey>*_keys){
//  keys=_keys;
//}
void Event::HandleEvent(GLFWwindow *window, int key, int scancode, int action, int mods, std::unordered_map<int, ButtonKey> *_keys){
  // tipe keys ...

  auto buttonKey = _keys->find(key) ;
  if (buttonKey == _keys->cend()) {
      return;
  }
  switch(action){
    case GLFW_PRESS:
        buttonKey->second.setState(ButtonState::Pressed);
      break;
    case GLFW_REPEAT:
        buttonKey->second.setState(ButtonState::Repeat);
      break;
    case GLFW_RELEASE:
        buttonKey->second.setState(ButtonState::Released);
      break;
  }
}
void Event::PreHandleEvent(std::unordered_map<int, ButtonKey> *_keys,Mouse *mouse){
//  keyboard keys only 
  for ( auto &item : ( *_keys ) ){
    if(item.second.getState() == ButtonState::Released){
      item.second.setState(ButtonState::None);
    }
  };
  //for ( auto &item : ( *mouseButtons ) ){
  //  item.second.setState(ButtonStates::None);
  //};
  mouse->whell=WhellState::None;
};
void Event::scroll_callback(GLFWwindow *window, double xoffset, double yoffset, Mouse *mouse){
  if( yoffset == 1 ){
    (*mouse).whell = WhellState::Up;
  }else{
    (*mouse).whell = WhellState::Down;
  }
}

void Event::mouse_callback(GLFWwindow *window, double xposIn, double yposIn, Mouse *mouse){

  mouse->x = (float)xposIn;
  mouse->y = (float)yposIn;
}
void Event::mouse_button_callback(GLFWwindow *window, int button, int action, int mods, std::unordered_map<int, ButtonKey> *mouse){

  auto buttonKey = mouse->find(button) ;
  if (buttonKey == mouse->cend()) {
      return;
  }
  switch(action){
    case GLFW_PRESS:
        buttonKey->second.setState(ButtonState::Pressed);
      break;
    case GLFW_REPEAT:
        buttonKey->second.setState(ButtonState::Repeat);
      break;
    case GLFW_RELEASE:
        buttonKey->second.setState(ButtonState::Released);
      break;
  }
  
}
