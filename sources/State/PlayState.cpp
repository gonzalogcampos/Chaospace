#include "PlayState.h"
#include <Render.h>
#include <Map.h>
#include "Game.h"
#include <iostream>

void PlayState::initState()
{
    type = State::PLAY;                       
    if(!loaded)
    {
        loaded = true;
        Map::getInstance()->init();
    }else
    {

    }
} 


void PlayState::update(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
    
        Game::getInstance()->setState(State::stateType::MENUFINAL);
    }
    Map::getInstance()->update(dt);

}


void PlayState::clear()
{

    loaded=false;
}