#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Game
{
private:
    sf::RenderWindow* win; 
    sf::Event evento; 
    sf::VideoMode videoMode; 
    
    void initVar();
    void initWin();  
    void initEnemies();

    //Game objects
    sf::RectangleShape enemy; 

public: 
    // constructors / destructors
    Game(); 
    virtual ~Game(); 

    // Acessors 
    const bool running() const; 
    // FUnctions 
    void pollEvents(); 
    void update(); 
    void render(); 

}; 