#include "PlayState.h"
#include <Render.h>
#include <Map.h>
#include <iostream>

void PlayState::initState()
{
    type = State::PLAY;                       
    std::cout<<"Play State inited\n";
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
    std::cout<<"update Play state\n";
    Map::getInstance()->update(dt);
}


void PlayState::clear()
{

    loaded=false;
}