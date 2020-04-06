#include "MenuState.h"
#include "Game.h"
#include <Render.h>

void MenuState::initState(){
    type = State::MENUINICIAL;

} 


void MenuState::update(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Game::getInstance()->setState(State::stateType::PLAY);
    }
    
}


void MenuState::clear(){}