//Main header
#include <NextLevelState.h>

//Headers
#include <Game.h>
#include <Render.h>

/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


void NextLevelState::initState(){
    
    type = State::NEXTLEVEL;
} 


void NextLevelState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                Game::getInstance()->setState(State::stateType::PLAY);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Render::getInstance()->close();

}

void NextLevelState::clear()
{

}