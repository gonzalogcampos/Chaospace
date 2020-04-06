#include "PlayState.h"
#include <Render.h>
#include <Map.h>

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
    Map::getInstance()->update(dt);
}


void PlayState::clear()
{

    loaded=false;
}