#include <iostream>
#include "Game.h"

int main () 
{ 
    //Init game engine 
    Game play; 
    // Game loop
    while (play.running())
    {
        while(win.pollEvent(evento))
        {
            // Update
            play.update(); 
            play.render(); 
        }
    }
    // Update 

    // Render
    win.clear(sf::Color::Magenta); // clear old frame
    
    // draw your game 
    win.display(); // Tell app that window is done drawing


    return 0; 
}