//Main header
#include <Game.h>

//Headers
#include <PlayState.h>
#include <FinalState.h>
#include <MenuState.h>
#include <TestState.h>
#include <Render.h>
#include <Clock.h>

//External headers
#include <stdlib.h>
#include <stdio.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


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
        case State::stateType::MENUFINAL:
            state = FinalState::getInstance();
            break;
    }
    state->initState();

    switch (this->state->type)
        {
        case State::stateType::TEST:
            break;
        case State::stateType::PLAY:
            break;
        case State::stateType::MENUINICIAL:
            break;
        case State::stateType::MENUFINAL:
            break;
        
        default:
            break;
        }
}