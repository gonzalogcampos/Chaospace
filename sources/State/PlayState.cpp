#include "PlayState.h"
#include <Render.h>
#include <Map.h>
#include <Game.h>
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
    if(!Map::getInstance()->update(dt))
    {
        Map::getInstance()->clear();
        loaded = false;
        Game::getInstance()->setState(State::MENUINICIAL);
    }
}


void PlayState::clear()
{

    loaded=false;
}