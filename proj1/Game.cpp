#include "Game.h"

Game::Game()
{
    this->initVar(); 
    this->initWin(); 
    this->initEnemies(); 
    this->initFonts(); 
    this->initTexts();  
}

Game::~Game()
{
    delete this->win; 
}

void Game::render()
{
    // clear old frame, render objects, display frame in window
    this->win->clear(sf::Color::Black); 
    
    // Draw game objects
    // this->win->draw(this->enemy);   
    this->renderEnemies(*this->win); 

    this->renderText(*this->win); 

    this->win->display(); 
}
void Game::renderEnemies(sf::RenderTarget &target)
{
    for(auto &e : this->enemies)
        target.draw(e);
    
}
void Game::renderText(sf::RenderTarget &target)
{
    target.draw(this->uiText); 
    
}
void Game::initVar()
{
    this->win = nullptr; 
    // game logic
    this->points = 0; 
    this->enemySpawnTimerMax = 100.f; 
    this->enemySpawnTimer = this->enemySpawnTimerMax; 
    this->maxEnemies = 5; 
    this->mouseHeld = false; 
    this->health = 10; 
    this->endgame = false; 
}
void Game::initWin()
{
    this->videoMode.height = 600; 
    this->videoMode.width = 800; 
    
    this->win = new sf::RenderWindow(this->videoMode, "game 1", sf::Style::Titlebar | sf::Style::Close);
    this->win->setFramerateLimit(60); 
}
void Game::initEnemies()
{
    this->enemy.setPosition(20.f, 20.f); 
    this->enemy.setSize(sf::Vector2f(100.f, 100.f)); 
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f)); 
    this->enemy.setFillColor(sf::Color::Cyan); 
    this->enemy.setOutlineColor(sf::Color::Green); 
    this->enemy.setOutlineThickness(1.f); 
}
void Game::initTexts()
{
    this->uiText.setFont(this->font); 
    this->uiText.setCharacterSize(20); 
    this->uiText.setFillColor(sf::Color::White); 
    this->uiText.setString("NONE"); 
}
void Game::initFonts()
{
    if(!this->font.loadFromFile("../Fonts/Dosis-Light.ttf"))    
    {
        std::cout << "Failed to load font" << "\n"; 
    }
}
void Game::pollEvents()
{
    while(this->win->pollEvent(this->evento))
    {
        switch(this->evento.type)
        {
        case sf::Event::Closed:
            this->win->close(); 
            break; 
        case sf::Event::KeyPressed: 
            if(evento.key.code == sf::Keyboard::Escape)
                win->close(); 
            break; 
        }
    }  
}
void Game::update()
{
    this->pollEvents(); 
    if(!this->endgame)
    {
    this->updateMousePos(); 
    this->updateEnemies(); 
    this->updateText(); 
    }
    if(this->health <= 0)
        this->endgame = true; 
}
void Game::updateMousePos()
{
    this->mouseposwin = sf::Mouse::getPosition(*this->win); 
    this->mousePosView = this->win->mapPixelToCoords(this->mouseposwin); 
}
void Game::updateEnemies()
{
    if(this->enemies.size() < this->maxEnemies)
    {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;          
        }
        else
            this->enemySpawnTimer += 1.f;
    }
        //moving enemies
        for(size_t i = 0; i < this->enemies.size(); i++)
        {
            bool deleted = false; 

            this->enemies[i].move(0.f, 1.f);

            if(this->enemies[i].getPosition().y > this->win->getSize().y){
                this->enemies.erase(this->enemies.begin() + i); 
                this->health -= 1; 
                std::cout << "Health: " << this->health << "\n"; 
            }

        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            bool deleted = false; 
            if(!this->mouseHeld)
            {
                this->mouseHeld = true; 
                for(size_t i = 0; i < this->enemies.size() && deleted == false; i++)    
                    if(this->enemies[i].getGlobalBounds().contains(this->mousePosView))
                    {                
                        deleted = true; 
                        this->enemies.erase(this->enemies.begin() + i);  
                        this->points += 1; 
                        std::cout << "Points: " << this->points << "\n"; 
                    }
                
            }
        }
        else 
            this->mouseHeld = false; 
}
void Game::updateText()
{
    std::stringstream ss; 
    ss << "Points: " << this->points << "\n" <<
    "Health: " << this->health <<"\n";
    this->uiText.setString(ss.str()); 
}
void Game::spawnEnemy()
{   
    // Set random position, color, add enemy to the vector
    this->enemy.setPosition(
    static_cast<float> (rand() % static_cast<int> (this->win->getSize().x - this->enemy.getSize().x)),
    0.f
    );
    this->enemy.setFillColor(sf::Color::Green); 
    this->enemies.push_back(this->enemy); 
}


// FUNCTIONS
// Acessors 
const bool Game::running() const
{
    return this->win->isOpen(); 
}
const bool Game::getEndGame() const
{
    return this->endgame;
}
