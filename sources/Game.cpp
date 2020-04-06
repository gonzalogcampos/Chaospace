#include <stdlib.h>
#include <stdio.h>
#include <Game.h>
#include <PlayState.h>
#include <MenuState.h>
#include <TestState.h>
#include <Render.h>
#include <Clock.h>


void Game::run()
{
    while(Render::getInstance()->isWindowOpen())
    {
        if(clock->canContinue())
        {
        Render::getInstance()->preLoop(clock->getElapsedTime());
        state->update(clock->getElapsedTime());
        Render::getInstance()->postLoop();
        }
    }
}


void Game::inicio()
{
    Render::getInstance()->init();
    clock = new Clock();
    setState(State::stateType::MENUINICIAL);
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
        case State::stateType::MENUINICIAL:
            state = MenuState::getInstance();
            break;
    }
    state->initState();

    switch (this->state->type)
        {
        case State::stateType::TEST:
            break;
        case State::stateType::MENUINICIAL:
            break;
        
        default:
            break;
        }
}