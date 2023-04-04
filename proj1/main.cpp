#include <iostream>
#include "Game.h"

int main () 
{ 
    //Init game engine 
    Game play; 
    // Game loop
    while (play.running())
    {  
        play.update(); 
        play.render(); 

    }

    return 0; 
}