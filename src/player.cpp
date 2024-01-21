#include "raylib.h"
#include <iostream>
class Player{
    public:
    Rectangle entity;
    float speedX, speedY;
    int jumps = 3;

    Player(float width, float height){
        entity = {width / 2, height / 2, 32, 32};
        speedX = 0;
        speedY = 0;
    }

    void moveFromMouse(){
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        speedX = (entity.x + 16 - mouseX) / 50;
        speedY = (entity.y + 16 - mouseY) / 50;
        while(speedX < 3 && speedX > -3 && speedY < 3 && speedY > -3){
            speedX *= 1.001;
            speedY *= 1.001;
        }
        if(speedX > 3){
            speedX += 3.2;
        }
        else if(speedX < -3){
            speedX += -3.2;
        }

        if(speedY > 3){
            speedY += 3;
        }
        else if(speedY < -3){
            speedY += -3;
        }
        jumps--;
    }
    
    void movement(float width, float height){
        entity.x += speedX;
        entity.y += speedY;
        if(speedX > 2 || speedX < -2){
            (speedX > 2) ? speedX -= 0.03 : ((speedX < -2) ? speedX += 0.03 : speedX = speedX);
        }
        else{
            speedX *= 0.99;
        }
        if(speedY < -7){
            speedY *= 0.8;
        }
        (speedY > 0) ? speedY -= 0.03: speedY += 0.03;
        speedY += 0.07;
        if(speedY > 2) { speedY -= (speedY - 2) * 0.1; }

        if(entity.x > width - entity.width){
            speedX = speedX * (-0.7);
            entity.x -= 3.5;
        }
        if(entity.x < 0){
            speedX = speedX * (-0.7);
            entity.x += 3.5;
        }
    }
};