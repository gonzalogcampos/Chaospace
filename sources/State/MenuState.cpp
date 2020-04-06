#include "MenuState.h"
#include "Game.h"
#include "Menu.h"
#include "Render.h"
#include "MainMenu.h"

void MenuState::initState(){
    
    type = State::MENUINICIAL;

     menu = new MainMenu();


} 


void MenuState::update(float dt){


    menu->update(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Game::getInstance()->setState(State::stateType::PLAY);
    }
    
}

void MenuState::clear(){}