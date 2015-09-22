//
//  Game.hpp
//  PongSfml
//
//  Created by Mukul Tamsekar on 22/09/15.
//  Copyright © 2015 Mukul Tamsekar. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#pragma once

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
    static void Start();
    
private:
    static bool IsExiting();
    static void GameLoop();
    
    static void ShowSplashScreen();
    static void ShowMenu();
    
    enum GameState { Unititialized , ShowingSplash, Pause, ShowingMenu, Playing, Exiting };
    
    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
    
};

#endif /* Game_hpp */
