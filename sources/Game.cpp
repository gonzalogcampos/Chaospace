//Main header
#include <Game.h>

//Headers
#include <PlayState.h>
#include <FinalState.h>
#include <MenuState.h>
#include <TestState.h>
#include <NextLevelState.h>
#include <ControlState.h>
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
        Render::getInstance()->preLoop(clock->getInterpolatedTime());
        if(clock->canContinue())
        {
            state->update(clock->getElapsedTime());
        }
        state->draw();
        Render::getInstance()->postLoop();
    }
}


void Game::inicio()
{
    Render::getInstance()->init(Rvect(1080, 720),  "Chaospace | The game 2020");
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
        case State::stateType::NEXTLEVEL:
            state = NextLevelState::getInstance();
            break;
        case State::stateType::CONTROLES:
            state = ControlState::getInstance();
            break;
    }
    state->initState();
}