//
//  Game.cpp
//  PongSfml
//
//  Created by Mukul Tamsekar on 22/09/15.
//  Copyright © 2015 Mukul Tamsekar. All rights reserved.
//

#include "Game.hpp"
#include "SplashScreen.hpp"
#include "MainMenu.hpp"

void Game::Start()
{
    if(_gameState != Unititialized)
    {
        return;
    }
    
    _mainWindow.create(sf::VideoMode(1024,768,32), "Pong !!!!!");
    _gameState = Game::ShowingSplash;
    
    while (!IsExiting()) {
        GameLoop();
    }
    
    _mainWindow.close();
    
}

bool Game::IsExiting()
{
    if(_gameState == Game::Exiting)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    
    while (_mainWindow.pollEvent(currentEvent)) {
        
        switch (_gameState) {
                
            case Game::ShowingSplash:
            {
                ShowSplashScreen();
                break;
            }
                
            case Game::ShowingMenu:
            {
                ShowMenu();
                break;
            }
                
            case Game::Playing:
            {
                _mainWindow.clear(sf::Color(255,0,0));
                _mainWindow.display();
                
                if(currentEvent.type == sf::Event::Closed)
                {
                    _gameState = Game::Exiting;
                }
                
                break;
            }
                
            default:
                break;
        }
        
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen ss;
    ss.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mm;
    MainMenu::MenuResult result = mm.Show(_mainWindow);
    
    switch (result) {
        case MainMenu::Exit:
            _gameState = Game::Exiting;
            break;
        
        case MainMenu::Play:
            _gameState = Game::Playing;
        default:
            break;
    }
}

Game::GameState Game::_gameState = Unititialized;
sf::RenderWindow Game::_mainWindow;

