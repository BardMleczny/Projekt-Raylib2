#include "raylib.h"
class Thing{
    public:
    Rectangle entity;
    int index;
    void Move(){
        entity.y -= 0.5;
    }
    Thing(float x, int index){
        entity = {x, 980, 20, 20};
        this -> index = index;
    }
    Thing(){
        entity = {0,0,0,0};
    }
};