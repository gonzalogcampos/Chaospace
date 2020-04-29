//Main header
#include <PlayState.h>

//Headers
#include <Render.h>
#include <Map.h>
#include <Game.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
    
        Game::getInstance()->setState(State::stateType::MENUFINAL);
    }

    if(!Map::getInstance()->update(dt))
    {
        loaded = false;
    }
}


void PlayState::clear()
{

    loaded=false;
}