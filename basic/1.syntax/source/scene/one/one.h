#pragma once
#include "../../objets/square/square.h"
#include "../../objets/abstract.h"

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
};

