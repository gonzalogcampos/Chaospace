#include "MenuState.h"
#include "Game.h"
#include <Render.h>
#include <iostream>

void MenuState::initState(){} 


void MenuState::update(float dt){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        
        clear();
        Game::getInstance()->setState(State::stateType::TEST);
    }
    
}


void MenuState::clear(){}