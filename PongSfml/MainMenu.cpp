//
//  MainMenu.cpp
//  PongSfml
//
//  Created by Mukul Tamsekar on 22/09/15.
//  Copyright © 2015 Mukul Tamsekar. All rights reserved.
//

#include "MainMenu.hpp"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow &window)
{
    sf::Texture image;
    image.loadFromFile("MainMenu.png");
    sf::Sprite sprite(image);
    
    MenuItem playButton;
    playButton.rect.top = 145;
    playButton.rect.height = 380;
    playButton.rect.left = 0;
    playButton.rect.width = 1023;
    playButton.action = Play;
    
    MenuItem exitButton;
    exitButton.rect.top = 383;
    exitButton.rect.left = 0;
    exitButton.rect.height = 560;
    exitButton.rect.width = 1023;
    exitButton.action = Exit;
    
    _menuitems.push_back(playButton);
    _menuitems.push_back(exitButton);
    
    window.draw(sprite);
    window.display();
    
    return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;
    
    for(it = _menuitems.begin(); it != _menuitems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        
        if(menuItemRect.contains(sf::Vector2<int>(x,y)))
        {
            return (*it).action;
        }
    }
    
    return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow &window)
{
    sf::Event menuEvent;
    
    while (true) {
        while (window.pollEvent(menuEvent)) {
            if(menuEvent.type == sf::Event::MouseButtonPressed)
            {
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}

