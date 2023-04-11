#pragma once
#include "../../objets/square/square.hpp"
#include "../../objets/cube/cube.hpp"
#include "../../objets/abstract.hpp"

class One{
  public:
    One(){};
    ~One(){};

    void Init();
    void Update();
    void Render();
    void Release();
    bool isRun;
  private:
    Objet * obj1 ;
    Objet * cube ;
};

