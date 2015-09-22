//
//  MainMenu.hpp
//  PongSfml
//
//  Created by Mukul Tamsekar on 22/09/15.
//  Copyright © 2015 Mukul Tamsekar. All rights reserved.
//

#pragma once

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

class MainMenu
{
public:
    enum MenuResult { Nothing, Exit, Play };
    
    struct MenuItem
    {
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };
    
    MenuResult Show(sf::RenderWindow& window);
    
private:
    MenuResult GetMenuResponse(sf::RenderWindow& window);
    MenuResult HandleClick(int x,int y);
    std::list<MenuItem> _menuitems;
    
};

#endif /* MainMenu_hpp */
