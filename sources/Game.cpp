#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include <PlayState.h>

void Game::run()
{
    inicio();

    while(true)
    {    
        state->update(0.1f);
    }
}

void Game::inicio()
{

    setState(State::stateType::PLAY);
}

void Game::setState(State::stateType type)
{
    switch(type)
    {
        case State::stateType::PLAY:
            state = PlayState::getInstance();
            break;

    }
    state->initState();
}