#include <stdlib.h>
#include <stdio.h>
#include <Game.h>
#include <PlayState.h>
#include <TestState.h>
#include <Render.h>

void Game::run()
{
    while(Render::getInstance()->isWindowOpen())
    {    
        Render::getInstance()->preLoop();
        
        state->update(0.1f);

        Render::getInstance()->postLoop();
    }
}

void Game::inicio()
{
    setState(State::stateType::PLAY);
    Render::getInstance()->init();
}

void Game::setState(State::stateType type)
{
    switch(type)
    {
        case State::stateType::PLAY:
            state = PlayState::getInstance();
            break;
        case State::stateType::TEST:
            state = TestState::getInstance();
            break;
    }
    state->initState();
}