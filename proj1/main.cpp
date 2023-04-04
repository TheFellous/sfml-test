#include "Game.h"

int main () 
{ 
    std::srand(static_cast<unsigned>(time(NULL))); 
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