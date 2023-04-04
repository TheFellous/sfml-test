#pragma once 

#include <iostream>
#include <vector>
#include <ctime>

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

    // Mouse position: 
    sf::Vector2i mouseposwin; 
    sf::Vector2f mousePosView; 
    // Game logic 
    int points; 
    float enemySpawnTimer; 
    float enemySpawnTimerMax; 
    int maxEnemies; 

    //Game objects

    std::vector<sf::RectangleShape> enemies; 
    sf::RectangleShape enemy; 

public: 
    // constructors / destructors
    Game(); 
    virtual ~Game(); 

    // Acessors 
    const bool running() const; 
    // FUnctions 
    void spawnEnemy(); 

    void pollEvents(); 
    void updateMousePos(); 
    void update(); 
    void updateEnemies(); 

    void renderEnemies(); 
    void render(); 

}; 