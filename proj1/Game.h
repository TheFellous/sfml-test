#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
    sf::RenderWindow *win;
    sf::Event evento;
    sf::VideoMode videoMode;

    void initVar();
    void initWin();
    void initEnemies();
    void initFonts();
    void initTexts();

    // Mouse position:
    sf::Vector2i mouseposwin;
    sf::Vector2f mousePosView;
    // Game logic
    bool endgame;
    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;

    // Resources
    sf::Font font;
    // Text
    sf::Text uiText;

    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

public:
    // constructors / destructors
    Game();
    virtual ~Game();

    // Acessors
    const bool running() const;
    const bool getEndGame() const;
    // FUnctions
    void spawnEnemy();

    void pollEvents();
    void updateMousePos();
    void update();
    void updateEnemies();
    void updateText();

    void renderEnemies(sf::RenderTarget &target);
    void renderText(sf::RenderTarget &target);
    void render();
};