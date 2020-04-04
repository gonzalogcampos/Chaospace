#include <stdlib.h>
#include <stdio.h>
#include <Game.h>
#include <PlayState.h>
#include <MenuState.h>
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
    setState(State::stateType::MENUINICIAL);
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