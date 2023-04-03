#include "Game.h"

Game::Game()
{
    this->initVar(); 
    this->initWin(); 
}

Game::~Game()
{
    delete this->win; 
}

void Game::update()
{
    while()
    {
        switch(evento.type)
        {
        case sf::Event::Closed:
            win->close(); 
            break; 
        case sf::Event::KeyPressed: 
            if(evento.key.code == sf::Keyboard::Escape)
                win->close(); 
            break; 
        }
    }
}

void Game::render()
{

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
}
void Game::pollEvents()
{
    
}
// FUNCTIONS


// Acessors 
const bool Game::running() const
{
    return this->win->isOpen(); 
}