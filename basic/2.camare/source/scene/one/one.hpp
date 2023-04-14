#pragma once
#include "../../objets/square/square.hpp"
#include "../../objets/cube/cube.hpp"
#include "../../objets/abstract.hpp"
#include "../../events/events.hpp"
#include "../../utils/camera/camera.hpp"
class One{
  public:
    One();
    ~One(){};

    void Init();
    void setKeys(std::unordered_map<int,ButtonKey> *_keys);
    void setMouse(Mouse *_mouse);
    void Update();
    void Render();
    void Release();
    bool isRun;
  private:
    Objet * obj1 ;
    Objet * cube ;
    std::unordered_map<int,ButtonKey>*keys;
    Mouse * mouse ;
    Camera * camera ;
};

