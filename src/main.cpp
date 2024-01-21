#include "raylib.h"
#include <iostream>
#include <sstream>
#include "thing.cpp"
#include "player.cpp"

Thing* GenerateThing(Thing things[]){
    Thing* thingToAdd = new Thing();
    for(int i = 0; i < 20; i++){
        if(things[i].entity.width == 0 || things[i].entity.y < 0){
            float randomX = rand() % 780;
            thingToAdd->entity = {randomX, 980, 20, 20};
            thingToAdd->index = i;
        }
    }
    return thingToAdd;
}
void CheckCollision(Player &player, Thing &thing){
    if(CheckCollisionRecs(thing.entity, player.entity)){
        player.jumps += 2;
        thing.entity.width = 0;
        thing.entity.x = -100;
    }   
}
void DrawJumps(int jumps){
    std::stringstream strs;
    strs << jumps;
    std::string tempStr = strs.str();
    char* jumpsChar = (char*) tempStr.c_str();
    Color color = {40, 40, 40, 80};
    DrawText(jumpsChar, GetScreenWidth() / 2, GetScreenHeight() / 2, 90, color);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Gamink");
    Player player(screenWidth, screenHeight);
    Thing things[20];
    
    int frameCounter = 0;
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawJumps(player.jumps);
        DrawRectangleRec(player.entity, BLACK);
        if(IsMouseButtonPressed(0)){
            if(player.jumps > 0){
                player.moveFromMouse();
            }
        }
        if(frameCounter % 180 == 0){
            for(int i = 0; i < 3; i++){
                Thing* newThing = GenerateThing(things);
                if(newThing->entity.width != 0){
                    things[newThing->index] = *newThing;
                }
                delete newThing;
            }
        }
        for(int i = 0; i < 20; i++){
            things[i].Move();
            DrawRectangleRec(things[i].entity, RED);
            CheckCollision(player, things[i]);
        }
        
        if(player.entity.y > screenHeight){
            player.entity = {screenWidth / 2, screenHeight / 2, 32, 32};
            player.jumps = 3;
            player.speedX = 0;
            player.speedY = 0;
            for(int i = 0; i < 20; i++){
                things[i].entity.width = 0;
            }
        }

        player.movement(screenWidth, screenHeight);
        EndDrawing();
        frameCounter++;
    } 

    CloseWindow();
    return 0;
}