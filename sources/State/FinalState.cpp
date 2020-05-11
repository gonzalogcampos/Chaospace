//Main header
#include <FinalState.h>

//Headers
#include <Game.h>
#include <Menu.h>
#include <Render.h>
#include <FinalMenu.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


void FinalState::initState()
{
    
    type = State::MENUFINAL;

    menu = new FinalMenu();

} 


void FinalState::update(float dt){

    menu->update(dt);

    if(Render::getInstance()->isEnterPressed()==true){
        switch (menu->click()){
            case 1: 
                /*MENU INICIAL*/
                delete menu; 
                Game::getInstance()->setState(State::stateType::MENUINICIAL);
                break;

            case 2: 
                /*EXIT*/
                delete menu; 
                Render::getInstance()->close();
                break;
            
            default: break;
        }

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        menu->down();   
    
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        menu->up();   
    
    
}

void FinalState::draw()
{
    menu->draw();
}

void FinalState::clear()
{

}