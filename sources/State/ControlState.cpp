//Main header
#include <ControlState.h>

//Headers
#include <Game.h>
#include <Menu.h>
#include <Render.h>
#include <ControlMenu.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


void ControlState::initState(){
    
    type = State::CONTROLES;

    menu = new ControlMenu();
} 


void ControlState::update(float dt){


    menu->update(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
        delete menu; 
        Game::getInstance()->setState(State::stateType::MENUINICIAL);
                
    }

}
    


void ControlState::draw()
{
    menu->draw();
}

void ControlState::clear()
{

}