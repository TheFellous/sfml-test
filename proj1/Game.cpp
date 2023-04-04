#include "Game.h"

Game::Game()
{
    this->initVar(); 
    this->initWin(); 
    this->initEnemies(); 
}

Game::~Game()
{
    delete this->win; 
}

void Game::update()
{
    this->pollEvents(); 
}

void Game::render()
{
    // clear old frame, render objects, display frame in window
    this->win->clear(sf::Color::Black); 
    
    // Draw game objects
    this->win->draw(this->enemy);   

    this->win->display(); 
}
void Game::initVar()
{
    this->win = nullptr; 
}
void Game::initWin()
{
    this->videoMode.height = 600; 
    this->videoMode.width = 800; 
    
    this->win = new sf::RenderWindow(this->videoMode, "game 1", sf::Style::Titlebar | sf::Style::Close);
    this->win->setFramerateLimit(144); 
}
void Game::initEnemies()
{
    this->enemy.setSize(sf::Vector2f(100.f, 100.f)); 
    this->enemy.setFillColor(sf::Color::Cyan); 
    this->enemy.setOutlineColor(sf::Color::Green); 
    this->enemy.setOutlineThickness(1.f); 
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
// FUNCTIONS


// Acessors 
const bool Game::running() const
{
    return this->win->isOpen(); 
}