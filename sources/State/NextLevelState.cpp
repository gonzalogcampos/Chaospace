//Main header
#include <NextLevelState.h>

//Headers
#include <Game.h>
#include <Render.h>
#include <Menu.h>
#include <TransitionMenu.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


void NextLevelState::initState(){
    
    type = State::NEXTLEVEL;
    menu = new TransitionMenu();
} 


void NextLevelState::update(float dt)
{
        menu->update(dt);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        switch (menu->click()){
            case 1: 
                /*PLAY*/
                delete menu; 
                Game::getInstance()->setState(State::stateType::PLAY);
                break;

            case 2: 
                /*EXIT*/
                delete menu; 
                Render::getInstance()->close();
                break;

            default: break;
        }

    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        menu->up();   
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        menu->down();   
    }

}

void NextLevelState::draw()
{
    menu->draw();
}


void NextLevelState::clear()
{

}